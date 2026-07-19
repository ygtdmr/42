/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupEnv.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/19 12:43:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/Client.hpp"
#include "../../../../inc/hpp/http/Headers.hpp"
#include "../../../../inc/hpp/utils/str.hpp"

void webserv::http::handler::Cgi::setupEnv( void )
{
	std::vector< std::pair<std::string, std::string> > const& headersVector(client->httpRequest.headers.getVector());
	std::vector< std::pair<std::string, std::string> >::const_iterator	it(headersVector.begin());
	while ( it != headersVector.end() )
	{
		if ( it->first == "Content-Length" )
			envStr_.push_back( "CONTENT_LENGTH=" + it->second );
		else if ( it->first == "Content-Type" )
			envStr_.push_back( "CONTENT_TYPE=" + it->second );
		else
		{
			std::string key( it->first );
			for ( size_t i = 0; i < key.size(); i++ )
			{
				if ( key[i] >= 'a' && key[i] <= 'z' )
					key[i] -= 32;
				else if ( key[i] == '-' )
					key[i] = '_';
			}
			key.insert( 0, "HTTP_" );
			envStr_.push_back( key + "=" + it->second );
		}
		it++;
	}
	envStr_.push_back( "SERVER_PORT=" + client->server->port );
	if ( client->httpRequest.version == "HTTP/1.1" )
		envStr_.push_back( "SERVER_NAME=" + client->httpRequest.headers["Host"].substr(0, client->httpRequest.headers["Host"].find(":")) );
	envStr_.push_back( "REDIRECT_STATUS=200" );
	envStr_.push_back( "GATEWAY_INTERFACE=CGI/1.1" );
	envStr_.push_back( "PATH_INFO=" + client->httpRequest.uriPath );
	envStr_.push_back( "REMOTE_ADDR=" + client->addr );
	envStr_.push_back( "REQUEST_METHOD=" + client->httpRequest.method );
	envStr_.push_back( "REQUEST_URI=" + client->httpRequest.uri ) ;
	envStr_.push_back( "QUERY_STRING=" + utils::str::crop( client->httpRequest.uri, "?" ) );
	envStr_.push_back( "SERVER_PROTOCOL=" + client->httpRequest.version );
	envStr_.push_back( "SCRIPT_NAME=" + client->httpRequest.uriPath );
	envStr_.push_back( "SCRIPT_FILENAME=" + realPath );
	for (size_t i = 0; i < envStr_.size(); i++)
		env_.push_back(const_cast< char* >( envStr_[i].c_str() ));
	env_.push_back( 0 );
}
