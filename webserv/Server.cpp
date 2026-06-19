/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:44:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/19 17:22:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
: serversConfig_( serversConfig ), serverConfig_( *serversConfig_.begin() )
{}

Server::Server( Server const& other )
: serversConfig_( other.serversConfig_ ), serverConfig_( *serversConfig_.begin() )
{}

Server::~Server()
{}

Server	&Server::operator=( Server const& other )
{
	if ( this != &other )
		this->serversConfig_ = other.serversConfig_;
	return ( *this );
}

void	Server::run( void )
{
	while (true)
	{
		int poll_count = poll(&(*pollFds_.begin()), pollFds_.size(), -1);

		if (poll_count <= 0)
			continue; 

	}
}

void	Server::setup( void )
{
	std::vector<ServerConfig>::const_iterator	it( serversConfig_.begin() );

	while ( it != serversConfig_.end() )
	{
		setupSocket();
		serverConfig_ = *it++;
	}
	for (size_t i = 0; i < listenSockets_.size(); i++)
		setupPoll( listenSockets_[i] );
}

void	Server::throwError( std::string const& msg ) const
{
	std::string			host( serverConfig_.host );
	std::stringstream	ss;

	if ( host.empty() )
		host = "[::]";
	ss	<< "server: "
		<< "(" << host << ":" << serverConfig_.port << ")"
		<< ": " << msg << std::endl;
	throw std::runtime_error( ss.str() );
}

void	Server::setupSocket( void )
{
	int	fd;

	fd = socket( AF_INET, SOCK_STREAM, 0 );
	listenSockets_.push_back( fd );
	if ( fd < 0 )
		throwError( std::string( "socket: " ) + strerror( errno ) );
	fcntl(fd, F_SETFL, O_NONBLOCK);

	addrinfo	hints = addrinfo();
	addrinfo	*res;
	const char	*host;

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	if ( serverConfig_.host.empty() )
		host = 0;
	else
		host = serverConfig_.host.c_str();
	if ( getaddrinfo( host, serverConfig_.port.c_str(), &hints, &res ) != 0 )
		throwError( std::string( "getaddrinfo: " ) + strerror( errno ) );
	if ( bind( fd, res->ai_addr, res->ai_addrlen ) < 0 )
		throwError( std::string( "bind: " ) + strerror( errno ) );
	freeaddrinfo( res );

	if (listen(fd, 128) < 0)
		throwError( std::string( "listen: " ) + strerror( errno ) );
}

void	Server::setupPoll( int fd  )
{
	struct pollfd	pfd;

	pfd.fd = fd;
	pfd.events = POLLIN;
	pfd.revents = 0;
	pollFds_.push_back( pfd );
}
