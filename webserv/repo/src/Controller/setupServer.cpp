/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupServer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 08:57:18 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 14:55:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <netdb.h>
#include <sys/socket.h>
#include <cerrno>
#include <cstring>
#include "Controller.hpp"
#include "config/Exception.hpp"

void webserv::Controller::setupServer( config::Server const* config,
									   char const*			 host,
									   char const*			 port )
{
	int				 fd( socket( AF_INET, SOCK_STREAM, 0 ) );
	int				 opt( 1 );
	http::Server server;

	if ( fd < 0 )
		throw config::Exception() << host << ":" << port << ", socket: " << strerror( errno );
	if ( setsockopt( fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof( opt ) ) < 0 )
		throw config::Exception() << host << ":" << port << ", setsockopt: " << strerror( errno );
	if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		throw config::Exception() << host << ":" << port << ", fcntl: " << strerror( errno );

	addrinfo  hints = addrinfo();
	addrinfo* res;

	hints.ai_family	  = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags	  = AI_PASSIVE;

	if ( getaddrinfo( host, port, &hints, &res ) != 0 )
		throw config::Exception() << host << ":" << port << ", getaddrinfo: " << strerror( errno );
	if ( bind( fd, res->ai_addr, res->ai_addrlen ) < 0 )
		throw config::Exception() << host << ":" << port << ", bind: " << strerror( errno );
	freeaddrinfo( res );
	if ( listen( fd, 128 ) < 0 )
		throw config::Exception() << host << ":" << port << ", listen: " << strerror( errno );

	if ( !host )
		host = "0.0.0.0";
	server.addr   = std::string( host );
	server.port   = std::string( port );
	server.config = config;
	server.fd = fd;
	newPollFd(fd);
	servers.push_back(server);
}
