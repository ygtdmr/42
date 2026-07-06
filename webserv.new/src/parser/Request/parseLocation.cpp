/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseLocation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:20:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 12:56:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"

void webserv::parser::Request::parseLocation()
{
	std::map< std::string, config::Location > const&		  locations( client->server->config->locations );
	std::map< std::string, config::Location >::const_iterator it( locations.begin() );
	std::string												  locationUri;

	while ( it != locations.end() )
	{
		if ( it->first.find( client->httpRequest.uri ) == 0 )
		{
			if ( !client->httpRequest.location || ( it->first.size() >= locationUri.size() ) )
			{
				client->httpRequest.location = &it->second;
				locationUri					 = it->first;
			}
		}
		it++;
	}
	if ( !client->httpRequest.location )
		throw http::Exception( 404 );
	currentState = HEADERS;
}
