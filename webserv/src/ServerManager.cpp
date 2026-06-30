/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerManager.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:53:00 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 12:35:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ServerManager.hpp"
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "../include/ConfigException.tpp"
#include "../include/ServerLog.tpp"

#define RECV_BUFFER_SIZE 8

ServerManager::ServerManager( void )
{
	pollFds_ = new std::vector< pollfd >;
	clients_ = new std::map< int, Client >;
	servers_ = new std::map< int, ServerConfig const* >;
}

ServerManager::ServerManager( ServerManager const& other )
{
	*this = other;
}

ServerManager::~ServerManager()
{
	delete pollFds_;
	delete clients_;
	delete servers_;
}

ServerManager& ServerManager::operator=( ServerManager const& other )
{
	if ( this != &other )
	{
		*pollFds_ = *other.pollFds_;
		*clients_ = *other.clients_;
		*servers_ = *other.servers_;
	}
	return *this;
}

void ServerManager::run( void )
{
	std::vector< pollfd >::iterator it_poll;
	while ( true )
	{
		if ( poll( &( *( pollFds_->begin() ) ), pollFds_->size(), -1 ) <= 0 )
			continue;
		it_poll = pollFds_->begin();
		while ( it_poll != pollFds_->end() )
		{
			if ( it_poll->revents & POLLIN )
			{
				if ( servers_->find( it_poll->fd ) != servers_->end() )
					acceptNewConnection( it_poll );
				else
					handleRead( it_poll );
			}
			if ( it_poll->revents & POLLOUT )
				handleWrite( it_poll );
			it_poll++;
		}
	}
}

void ServerManager::setupServers( std::vector< ServerConfig > const& serversConfig )
{
	std::vector< ServerConfig >::const_iterator it( serversConfig.begin() );
	ServerLog( "INFO" ) << "Initializing servers..." << '\n';
	while ( it != serversConfig.end() )
	{
		int fd( setupSocket( *it ) );
		( *servers_ )[fd] = &( *it );
		pollFds_->push_back( toPollFd( fd ) );
		ServerLog( *it, "SUCCESS" ) << "Server initialized." << '\n';
		it++;
	}
}

void ServerManager::acceptNewConnection( std::vector< pollfd >::iterator& itPoll )
{
	ServerConfig const& serverConfig( *( servers_->find( itPoll->fd )->second ) );
	sockaddr_in			clientAddr;
	socklen_t			clientLen( sizeof( clientAddr ) );
	int					clientFd( accept( itPoll->fd, ( sockaddr* )&clientAddr, &clientLen ) );

	if ( clientFd < 0 )
		return;
	if ( fcntl( clientFd, F_SETFL, O_NONBLOCK ) < 0 )
		return;
	Client client( serverConfig );
	client.address = clientAddr;
	clients_->insert( std::make_pair( clientFd, client ) );
	pollFds_->push_back( toPollFd( clientFd ) );
	itPoll = pollFds_->begin();
	ServerLog( serverConfig, "WARNING" ) << "New connection from: " << inet_ntoa( clientAddr.sin_addr )
										 << ", assigned socket: " << clientFd << '\n';
}

void ServerManager::handleRead( std::vector< pollfd >::iterator& itPoll )
{
	Client& client( clients_->find( itPoll->fd )->second );
	char	buffer[RECV_BUFFER_SIZE];
	ssize_t bytesRead( recv( itPoll->fd, buffer, sizeof( buffer ) - 1, 0 ) );

	if ( bytesRead == 0 )
		return closeConnection( itPoll, "client side close" );
	else if ( bytesRead > 0 )
	{
		client.requestBuffer.append( buffer, bytesRead );
		if ( client.parseRequest() )
		{
			ServerLog( client.serverConfig, "INFO" )
				<< "Request received from: " << inet_ntoa( client.address.sin_addr )
				<< ", assigned socket: " << itPoll->fd << ", request_uri=[" << client.request->uri
				<< "], method=[" << client.request->method << "]" << '\n';
			itPoll->events = POLLOUT;
		}
	}
}

void ServerManager::handleWrite( std::vector< pollfd >::iterator& itPoll )
{
	Client&			   client( clients_->find( itPoll->fd )->second );
	HttpRequest const& httpRequest( *client.request );
	HttpResponse	   httpResponse;
	std::string		   connection( "keep-alive" );

	if ( httpRequest.headers.find( "Connection" ) != httpRequest.headers.end() )
		connection = httpRequest.headers.find( "Connection" )->second;
	if ( httpRequest.errorCode )
		httpResponse.generateErrorPage( httpRequest.errorCode, client.serverConfig.errorPages );
	else if ( httpRequest.isRedirect )
		httpResponse.generateRedirect( httpRequest.location->redirect );
	else if ( httpRequest.isDirectoryListing )
		httpResponse.generateDirectoryListing( httpRequest.location->root,
											   ServerConfig::uriToPath( httpRequest.uri ) );
	else if ( httpRequest.method == "GET" )
		httpResponse.handleGet( *httpRequest.location, ServerConfig::uriToPath( httpRequest.uri ) );
	else if ( httpRequest.method == "DELETE" )
		httpResponse.handleDelete( *httpRequest.location, ServerConfig::uriToPath( httpRequest.uri ) );
	else if ( httpRequest.method == "POST" )
		httpResponse.handlePost( *httpRequest.location, httpRequest );
	std::string data( httpResponse.build( httpRequest.version, connection ) );
	send( itPoll->fd, data.c_str(), data.length(), 0 );
	ServerLog( client.serverConfig, "INFO" )
		<< "Response sent to: " << inet_ntoa( client.address.sin_addr ) << ", assigned socket: " << itPoll->fd
		<< ", uri=[" << httpRequest.uri << "], status=[" << httpResponse.statusCode << "]" << '\n';
	client.clear();
	if ( connection == "close" )
		closeConnection( itPoll, "server side closed" );
	itPoll->events = POLLIN;
}

void ServerManager::closeConnection( std::vector< pollfd >::iterator& itPoll, std::string const& reason )
{
	int		clientFd( itPoll->fd );
	Client& client( clients_->find( clientFd )->second );

	close( clientFd );
	ServerLog( client.serverConfig, "WARNING" )
		<< "Connection closed from: " << inet_ntoa( client.address.sin_addr )
		<< ", assigned socket: " << clientFd << ", reason: " << reason << '\n';
	pollFds_->erase( itPoll );
	clients_->erase( clientFd );
	itPoll = pollFds_->begin();
}

int ServerManager::setupSocket( ServerConfig const& serverConfig )
{
	int fd( socket( AF_INET, SOCK_STREAM, 0 ) );
	int opt( 1 );

	if ( fd < 0 )
		throw ConfigException( serverConfig ) << "socket: " << strerror( errno );
	if ( setsockopt( fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof( opt ) ) < 0 )
		throw ConfigException( serverConfig ) << "setsockopt: " << strerror( errno );
	if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		throw ConfigException( serverConfig ) << "fcntl: " << strerror( errno );

	addrinfo	hints = addrinfo();
	addrinfo*	res;
	char const* host;
	hints.ai_family	  = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags	  = AI_PASSIVE;

	if ( serverConfig.host.empty() )
		host = 0;
	else
		host = serverConfig.host.c_str();
	if ( getaddrinfo( host, serverConfig.port.c_str(), &hints, &res ) != 0 )
		throw ConfigException( serverConfig ) << "getaddrinfo: " << strerror( errno );
	if ( bind( fd, res->ai_addr, res->ai_addrlen ) < 0 )
		throw ConfigException( serverConfig ) << "bind: " << strerror( errno );
	freeaddrinfo( res );
	if ( listen( fd, 128 ) < 0 )
		throw ConfigException( serverConfig ) << "listen: " << strerror( errno );
	return fd;
}

pollfd ServerManager::toPollFd( int fd )
{
	pollfd pfd;

	pfd.fd		= fd;
	pfd.events	= POLLIN;
	pfd.revents = 0;
	return pfd;
}
