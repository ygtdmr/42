/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 23:06:53 by yidemir          ###   ########.fr       */
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
		if ( currentState == CHUNKED_BODY || currentState == BODY )
		{
			checkMaxBodySize();
			bool isChunkedBodyDone( currentState == CHUNKED_BODY && ( chunkedBuffer.find( "0\r\n\r\n" ) == 0 ) );
			bool isBodyDone( currentState == BODY && ( client->httpRequest.bodySize >= contentLength_ ) );
			if ( isBodyDone || isChunkedBodyDone )
				currentState = DONE;
			if ( client->httpRequest.isCgi && ( client->httpRequest.bodySize > 0 ) )
				client->controller->getPollfd(client->fd).events = POLLOUT;
		}
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
