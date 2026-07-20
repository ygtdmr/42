/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Exception.hpp"
#include "http/Client.hpp"
#include "parser/Request.hpp"

void webserv::parser::Request::parse( void )
{
	try
	{
		if ( currentState == REQUEST_FIRST_LINE )
			parseFirstLine();
		if ( currentState == LOCATION )
		{
			parseLocation();
			parseCgiBin();
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
