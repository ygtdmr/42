/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:44:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/26 09:01:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <ctime>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "Server.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

Server::Server( std::vector<ServerConfig>& serversConfig )
: serversConfig_( serversConfig ), pollFds_( 0 ), clients_( 0 ), sockets_( 0 )
{}

Server::Server( Server const& other )
: serversConfig_( other.serversConfig_ )
{
	*this = other;
}

Server::~Server()
{
	if ( pollFds_ )
		delete pollFds_;
	if ( clients_ )
		delete clients_ ;
	if ( sockets_)
		delete sockets_;
}

Server	&Server::operator=( Server const& other )
{
	if ( this != &other )
	{
		serversConfig_ = other.serversConfig_;
		if ( pollFds_ )
			*pollFds_ = *other.pollFds_;
		if ( clients_ )
			*clients_ = *other.clients_;
		if ( sockets_ )
			*sockets_ = *other.sockets_;
	}
	return ( *this );
}

void	Server::run( void )
{
	while ( true )
	{
		if ( poll( &( *( pollFds_->begin() ) ), pollFds_->size(), -1 ) <= 0 )
			continue ;
		for ( size_t i = 0; i < pollFds_->size(); i++ )
		{
			int	fd( (*pollFds_)[i].fd );

			if ( (*pollFds_)[i].revents & POLLIN )
			{
				if ( sockets_->find( fd ) != sockets_->end() )
				{
					sockaddr_in	clientAddr;
					socklen_t	clientLen( sizeof( clientAddr ) );
					int			clientFd( accept(fd, ( sockaddr* )&clientAddr, &clientLen ) );

					if ( clientFd >= 0 )
					{
						fcntl( clientFd, F_SETFL, O_NONBLOCK ); 
						clients_->insert( std::make_pair( clientFd, Client( clientAddr, *( sockets_->find( fd )->second ) ) ) );
						pollFds_->push_back( toPollFd( clientFd ) );
						printMsg_ << "New connection from: " << inet_ntoa( clientAddr.sin_addr ) << ", assigned socket: " << clientFd;
						printLog( "WARNING" );
					}
				}
				else
				{
					char	buffer[CLIENT_READ_BUFFER];
					ssize_t	bytesRead( recv( fd, buffer, sizeof( buffer ) - 1, 0 ) );
					Client	&client( clients_->find(fd)->second );

					if ( bytesRead > 0 )
					{
						buffer[bytesRead] = 0;
						client.read( buffer, bytesRead );
						if ( client.isReadEnd() )
							(*pollFds_)[i].events = POLLOUT;
					}
					else
					{
						close( fd );
						printMsg_ << "Connection closed from: " << inet_ntoa( client.addr.sin_addr ) << ", assigned socket: " << fd;
						printLog( "ERROR" );
						pollFds_->erase( pollFds_->begin() + i );
						clients_->erase( fd );
						i--;
					}
				}
			}
			if ( (*pollFds_)[i].revents & POLLOUT )
			{
				Client	&client( clients_->find(fd)->second );
				printMsg_	<< "Request recived from: " << inet_ntoa( client.addr.sin_addr ) << ", assigned socket: " << fd
							<< ", request_uri=[" << client.requestUri << "], method=[" << client.method << "]";
				printLog( "INFO" );
				Response	response( client );
				std::string	data( response.process() );
				send( fd, data.c_str(), data.length(), 0 );
				printMsg_	<< "Response sent to: " << inet_ntoa( client.addr.sin_addr ) << ", assigned socket: " << fd
							<< ", status=[" << response.statusCode << "]";
				printLog( "INFO" );
				if ( ( client.headers.find("Connection") != client.headers.end() ) && client.headers["Connection"] == "close" )
				{
					close( fd );
					pollFds_->erase( pollFds_->begin() + i );
					clients_->erase( fd );
					i--;
				}
				else
				{
					client = Client( client.addr, client.serverConfig );
					(*pollFds_)[i].events = POLLIN;
				}
			}
		}
	}
}

void	Server::setup( void )
{
	std::vector<ServerConfig>::iterator	it( serversConfig_.begin() );

	pollFds_ = new std::vector<pollfd>;
	clients_ = new std::map<int, Client>;
	sockets_ = new std::map<int, ServerConfig*>;
	printMsg_ << "Initializing servers...";
	printLog( "INFO" );
	while ( it != serversConfig_.end() )
	{
		int	fd( setupSocket( *it ) );

		(*sockets_)[fd] = &(*it);
		pollFds_->push_back( toPollFd( fd ) );
		printMsg_ << "Server initialized: host=[" << it->host << "], port=[" << it->port << "]";
		printLog( "SUCCESS" );
		it++;
	}
}

void	Server::printLog( std::string const &level )
{
	char		buffer[80];
	std::time_t	rawtime;
	char const	*color( "RESET" );

	std::time( &rawtime );
	std::tm*	timeinfo( std::localtime( &rawtime ) );
	std::strftime( buffer, sizeof( buffer ), "[%Y-%m-%d %H:%M:%S]", timeinfo );
	if (level == "INFO")
		color = CYAN;
	else if (level == "ERROR")
		color = RED;
	else if (level == "SUCCESS") 
		color = GREEN;
	else if (level == "WARNING") 
		color = YELLOW;
	std::cout << color << buffer << " [" << level << "] " << printMsg_.str() << RESET << std::endl;
	printMsg_.clear();
	printMsg_.str( "" );
}

void	Server::throwError( ServerConfig const& serverConfig, std::string const& msg ) const
{
	std::string			host( serverConfig.host );
	std::stringstream	ss;

	if ( host.empty() )
		host = "[::]";
	ss	<< "server: "
		<< "(" << host << ":" << serverConfig.port << ")"
		<< ": " << msg;
	throw std::runtime_error( ss.str() );
}

int	Server::setupSocket( ServerConfig const& serverConfig )
{
	int	fd( socket( AF_INET, SOCK_STREAM, 0 ) );
	int	opt( 1 );

	if ( fd < 0 )
		throwError( serverConfig, std::string( "socket: " ) + strerror( errno ) );
	if ( setsockopt( fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof( opt ) ) < 0 )
		throwError( serverConfig, std::string( "setsockopt: " ) + strerror( errno ) );
	if ( fcntl(fd, F_SETFL, O_NONBLOCK) < 0 )
		throwError( serverConfig, std::string( "fcntl: " ) + strerror( errno ) );
	addrinfo	hints = addrinfo();
	addrinfo	*res;
	const char	*host;

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if ( serverConfig.host.empty() )
		host = 0;
	else
		host = serverConfig.host.c_str();
	if ( getaddrinfo( host, serverConfig.port.c_str(), &hints, &res ) != 0 )
		throwError( serverConfig, std::string( "getaddrinfo: " ) + strerror( errno ) );
	if ( bind( fd, res->ai_addr, res->ai_addrlen ) < 0 )
		throwError( serverConfig, std::string( "bind: " ) + strerror( errno ) );
	freeaddrinfo( res );

	if (listen(fd, 128) < 0)
		throwError( serverConfig, std::string( "listen: " ) + strerror( errno ) );
	return ( fd );
}

pollfd	Server::toPollFd( int fd  )
{
	pollfd	pfd;

	pfd.fd = fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	return ( pfd );
}
