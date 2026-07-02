/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 19:36:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/chunkedBody.hpp"
#include "../../../inc/hpp/parser/headers.hpp"
#include "../../../inc/hpp/parser/requestFirstLine.hpp"
#include "../../../inc/hpp/utils/map.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parse( void )
{
	try
	{
		if ( currentState == REQUEST_FIRST_LINE )
		{
			if ( !utils::str::has( *receiveData, "\n" ) )
				return;
			requestFirstLine( *receiveData, *request );
			currentState = HEADERS;
		}
		if ( currentState == HEADERS )
		{
			if ( !( utils::str::has( *receiveData, "\r\n\r\n" ) || utils::str::has( *receiveData, "\n\n" ) ) )
				return;
			request->headers = headers( *receiveData );
			if ( utils::map::isEq< std::string, std::string >(
					 request->headers, "Transfer-Encoding", "chunked" ) )
				currentState = CHUNKED_BODY;
			else if ( utils::map::has< std::string, std::string >( request->headers, "Content-Length" ) )
				currentState = BODY;
			else
				currentState = DONE;
		}
		if ( currentState == CHUNKED_BODY )
		{
			request->body += chunkedBody( *receiveData );
			if ( isChunkedBodyDone( *receiveData ) )
				currentState = DONE;
		}
		if ( currentState == BODY )
		{
			request->body += *receiveData;
			if ( isBodyDone() )
				currentState = DONE;
		}
	}
	catch ( std::exception const& _ )
	{
		request->status = 400;
		currentState = DONE;
	}
}
