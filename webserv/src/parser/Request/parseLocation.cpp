/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseLocation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:20:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 15:15:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"

void webserv::parser::Request::parseLocation()
{
	std::vector< config::Location >::const_iterator it( client->server->config->locations.begin() );
	std::string										locationUri;

	while ( it != client->server->config->locations.end() )
	{
		if ( client->httpRequest.uri.find( it->uriPath ) == 0 )
		{
			if ( !client->httpRequest.location || ( it->uriPath.size() > locationUri.size() ) )
			{
				client->httpRequest.location = &( *it );
				locationUri					 = it->uriPath;
			}
		}
		it++;
	}
	if ( !client->httpRequest.location )
		throw http::Exception( 404 );

	if ( !client->httpRequest.location->allowMethods.empty() )
	{
		bool allowMethod( false );
		for ( size_t i = 0; !allowMethod && ( i < client->httpRequest.location->allowMethods.size() ); i++ )
			allowMethod =
				client->httpRequest.method == *( client->httpRequest.location->allowMethods.begin() + i );
		if ( !allowMethod )
			throw http::Exception( 405 );
	}
	currentState = HEADERS;
}
