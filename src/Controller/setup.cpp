/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Controller.hpp"
#include "http/Log.hpp"
#include "http/Server.hpp"
#include "utils/str.hpp"

void webserv::Controller::setup( std::vector< config::Server > const& servers )
{
	http::Log( "INFO" ) << "Initializing servers..." << '\n';
	for ( size_t cI = 0; cI < servers.size(); cI++ )
	{
		for ( size_t sI = 0; sI < servers[cI].listens.size(); sI++ )
		{
			std::string listen( servers[cI].listens[sI] );
			char const* host( 0 );
			char const* port;
			if ( utils::str::has( listen, ":" ) )
			{
				host = listen.substr( 0, listen.find( ":" ) ).c_str();
				port = listen.substr( listen.find( ":" ) + 1 ).c_str();
			}
			else
				port = listen.c_str();
			setupServer( &servers[cI], host, port );
			http::Log( *( this->servers.end() - 1 ), "SUCCESS" ) << "Server initialized." << '\n';
		}
	}
}
