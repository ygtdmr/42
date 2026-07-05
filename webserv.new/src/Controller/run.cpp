/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 08:41:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hpp/Controller.hpp"
#include "../../hpp/ServerLog.hpp"
#include "../../hpp/manager/Client.hpp"
#include "../../hpp/manager/Server.hpp"
#include "signal.h"

bool g_webserv_exit( 0 );

static void webserv_exit( int )
{
	g_webserv_exit = true;
}

namespace webserv
{

void Controller::run( void ) const
{
	signal( SIGQUIT, SIG_IGN );
	signal( SIGTSTP, SIG_IGN );
	signal( SIGPIPE, SIG_IGN );
	signal( SIGINT, webserv_exit );
	while ( !g_webserv_exit )
	{
		if ( poll( &( *( pollfds_->begin() ) ), pollfds_->size(), -1 ) <= 0 )
			continue;
		for ( size_t i = 0; i < pollfds_->size(); i++ )
		{
			manager::Server* server( dynamic_cast< manager::Server* >( &( *connections_ )[i] ) );
			if ( server )
				acceptConnection( i );
			else
			{
				manager::Client* client( dynamic_cast< manager::Client* >( &( *connections_ )[i] ) );
				client->process();
				if ( client->isConnectionClose )
					closeConnection( i--, "client side" );
			}
		}
	}
	ServerLog( "WARNING" ) << "webserv closing..." << '\n';
}

}  // namespace webserv
