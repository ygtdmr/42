/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 17:25:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <cerrno>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/ServerLog.hpp"
#include "../../inc/hpp/manager/Client.hpp"
#include "../../inc/hpp/manager/Server.hpp"

#define CLIENT_TIMEOUT 30

bool g_webserv_exit( 0 );

static void webserv_exit( int )
{
	g_webserv_exit = true;
}

namespace webserv
{

void Controller::run( void ) const throw()
{
	std::time_t currentTime;
	signal( SIGQUIT, SIG_IGN );
	signal( SIGTSTP, SIG_IGN );
	signal( SIGPIPE, SIG_IGN );
	signal( SIGINT, webserv_exit );
	while ( !g_webserv_exit )
	{
		if ( poll( &( *( pollfds->begin() ) ), pollfds->size(), 1000 ) < 0 )
		{
			if ( errno == EINTR )
				continue;
			break;
		}
		currentTime = std::time( 0 );
		for ( size_t i = 0; i < pollfds->size(); i++ )
		{
			( *connections )[i]->pollfd = &( *pollfds )[i];
			manager::Server* server( dynamic_cast< manager::Server* >( ( *connections )[i] ) );
			if ( server )
				acceptConnection( i );
			else
			{
				manager::Client* client( dynamic_cast< manager::Client* >( ( ( *connections )[i] ) ) );
				client->posPoll = &i;
				if ( ( currentTime - client->lastActivity ) > CLIENT_TIMEOUT )
					closeConnection( i--, "timeout" );
				else
				{
					client->process();
					if ( client->isConnectionClose )
						closeConnection( i--, "client side" );
				}
			}
		}
	}
	ServerLog( "WARNING" ) << "webserv closing..." << '\n';
}

}  // namespace webserv
