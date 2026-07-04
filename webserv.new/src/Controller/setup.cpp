/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 18:44:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include "../../hpp/ServerLog.hpp"
#include "../../hpp/Controller.hpp"
#include "../../hpp/config/Exception.hpp"
#include "../../hpp/manager/Server.hpp"
#include "../../hpp/utils/str.hpp"

namespace webserv
{

static manager::Server setupServer( config::Server const* config, char const* host, char const* port )
{
	manager::Server server;
	int				fd( socket( AF_INET, SOCK_STREAM, 0 ) );
	int				opt( 1 );

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

	server.config		  = config;
	server.addr			  = host;
	server.port			  = port;
	server.pollfd.fd	  = fd;
	server.pollfd.events  = POLLIN;
	server.pollfd.revents = 0;
	return server;
}

void Controller::setup( std::vector< config::Server > const* servers )
{
	ServerLog( "INFO" ) << "Initializing servers..." << '\n';
	for ( size_t cI = 0; cI < servers->size(); cI++ )
	{
		for ( size_t sI = 0; cI < ( *servers )[cI].listens.size(); cI++ )
		{
			std::string listen( ( *servers )[cI].listens[sI] );
			char const* host( 0 );
			char const* port;
			if ( utils::str::has( listen, ":" ) )
			{
				host = listen.substr( 0, listen.find( ":" ) ).c_str();
				port = listen.substr( listen.find( ":" ) + 1 ).c_str();
			}
			else
				port = listen.c_str();
			manager::Server server( setupServer( &( *servers )[cI], host, port ) );
			pollfds_->push_back( server.pollfd );
			connections_->push_back( server );
			ServerLog( server, "SUCCESS" ) << "Server initialized." << '\n';
		}
	}
}

}  // namespace webserv
