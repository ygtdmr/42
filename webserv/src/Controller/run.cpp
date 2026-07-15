/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 23:32:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <cerrno>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/http/Log.hpp"

#define CLIENT_TIMEOUT 30

bool g_webserv_exit( 0 );

static void webserv_exit( int )
{
	g_webserv_exit = true;
}

void webserv::Controller::run( void ) throw()
{
	std::time_t currentTime;
	signal( SIGQUIT, SIG_IGN );
	signal( SIGTSTP, SIG_IGN );
	signal( SIGPIPE, SIG_IGN );
	signal( SIGINT, webserv_exit );
	while ( !g_webserv_exit )
	{
		if ( poll( &(*pollfds.begin()), pollfds.size(), 1000 ) < 0 )
		{
			if ( errno == EINTR )
				continue;
			break;
		}
		currentTime = std::time( 0 );
		std::vector< http::Server >::const_iterator itServer(servers.begin());
		while (itServer != servers.end())
			acceptConnection(*itServer++);
		std::vector< http::Client >::iterator itClient(clients.begin());
		while (itClient != clients.end())
		{
			if ( ( currentTime - itClient->lastActivity ) > CLIENT_TIMEOUT )
					closeConnection( itClient, "timeout" );
			else
			{
				itClient->process();
				if ( itClient->isConnectionClose )
					closeConnection( itClient, "client side" );
				else
					itClient++;
			}
		}
	}
	http::Log( "WARNING" ) << "webserv closing..." << '\n';
}
