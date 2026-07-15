/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/15 13:30:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"

void webserv::parser::Request::parse( void )
{
	try
	{
		if ( currentState == REQUEST_FIRST_LINE )
			parseFirstLine();
		if ( currentState == LOCATION )
		{
			parseLocation();
			parseIsCgi();
		}
		if ( currentState == HEADERS )
			parseHeaders();
		if ( currentState == CHUNKED_BODY )
			parseChunkedBody();
		if ( currentState == BODY )
			parseBody();
	}
	catch ( http::Exception const& e )
	{
		if ( client->handler )
		{
			delete client->handler;
			client->handler = 0;
		}
		client->httpRequest.status = e.status;
		currentState			   = DONE;
	}
}
