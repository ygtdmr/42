/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:44:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/21 20:45:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <sstream>
#include <stdexcept>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "Server.hpp"

Server::Server( std::vector<ServerConfig>& serversConfig )
: serversConfig_( serversConfig ), pollFds_( 0 ), clients_( 0 ), sockets_( 0 )
{}

Server::Server( Server const& other )
: serversConfig_( other.serversConfig_ ), pollFds_( 0 ), clients_( 0 ), sockets_( 0 )
{}

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
		this->serversConfig_ = other.serversConfig_;
		if ( this->pollFds_ )
			*(this->pollFds_ ) = *other.pollFds_;
		if ( this->clients_ )
			*(this->clients_ ) = *other.clients_;
		if ( this->sockets_ )
			*(this->sockets_) = *other.sockets_;
	}
	return ( *this );
}

void	Server::run( void )
{
	while ( true )
	{
		std::vector<pollfd>::iterator	it( pollFds_->begin() );

		if ( poll( &( *( pollFds_->begin() ) ), pollFds_->size(), -1 ) <= 0 )
			continue ;
		while ( it != pollFds_->end() )
		{
			int			&fd( (*it).fd );
			short int	&events( (*it).events );

			if ( events & POLLIN )
			{
				if ( sockets_->find( fd ) != sockets_->end() )
				{
					struct sockaddr_in	clientAddr;
					socklen_t			clientLen( sizeof( clientAddr ) );
					int					clientFd( accept(fd, (struct sockaddr*)&clientAddr, &clientLen) );

					if ( clientFd >= 0 )
					{
						fcntl(clientFd, F_SETFL, O_NONBLOCK); 
						(*clients_)[clientFd] = Client( sockets_->find( fd )->second );
						pollFds_->push_back( toPollFd( clientFd ) );
					}
				}
				else
				{
					char	buffer[CLIENT_READ_BUFFER];
					ssize_t	bytesRead( recv( fd, buffer, sizeof( buffer ) - 1, 0 ) );
					Client	&client( (*clients_)[fd] );

					if ( bytesRead > 0 )
					{
						buffer[bytesRead] = 0;
						client.read( buffer, bytesRead );
						if ( client.status > 0 )
							events = POLLOUT;
					}
					else
					{
						close( fd );
						pollFds_->erase( it );
						clients_->erase( fd );
					}
				}
			}
			if ( events & POLLOUT )
			{
				Response	response( (*clients_)[fd] );
				std::string	data( response.process() );
				send( fd, data.c_str(), data.length(), 0 );
				close( fd );
				pollFds_->erase( it );
				clients_->erase( fd );
			}
			it++;
		}
	}
}

void	Server::setup( void )
{
	std::vector<ServerConfig>::const_iterator	it( serversConfig_.begin() );

	pollFds_ = new std::vector<pollfd>;
	clients_ = new std::map<int, Client>;
	sockets_ = new std::map<int, ServerConfig&>;
	while ( it != serversConfig_.end() )
	{
		int	fd( setupSocket( *it ) );

		(*sockets_)[fd] = *it;
		pollFds_->push_back( toPollFd( fd ) );
		it++;
	}
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

	if ( setsockopt( fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof( opt ) ) < 0 )
		throwError( serverConfig, std::string( "setsockopt: " ) + strerror( errno ) );
	if ( fd < 0 )
		throwError( serverConfig, std::string( "socket: " ) + strerror( errno ) );
	fcntl(fd, F_SETFL, O_NONBLOCK);

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
	struct pollfd	pfd;

	pfd.fd = fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	return ( pfd );
}
