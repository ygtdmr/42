/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 11:33:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../inc/hpp/utils/conv.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseHeaders( void )
{
	client->httpRequest.body += client->receiveData;
	client->receiveData.clear();
	if ( !( utils::str::has( client->httpRequest.body, "\r\n\r\n" ) ||
			utils::str::has( client->httpRequest.body, "\n\n" ) ) )
		return;
	std::map< std::string, std::string >& headers( client->httpRequest.headers );
	try
	{
		headers = headersToMap( client->httpRequest.body );
	}
	catch ( std::exception const& _ )
	{
		throw http::Exception( 400 );
	}
	if ( client->httpRequest.version == "HTTP/1.1" )
	{
		if ( headers["Host"].empty() )
			throw http::Exception( 400 );
		if ( headers["Transfer-Encoding"] == "chunked" )
		{
			chunkedBuffer = client->httpRequest.body;
			client->httpRequest.body.clear();
			currentState = CHUNKED_BODY;
		}
		else if ( !headers["Content-Length"].empty() )
			currentState = BODY;
		else
			currentState = DONE;
	}
	else if ( !headers["Content-Length"].empty() )
		currentState = BODY;
	else
		currentState = DONE;
	if ( !headers["Content-Length"].empty() )
	{
		size_t clientMaxBodySize( 0 );
		if ( client->httpRequest.location )
			clientMaxBodySize = client->httpRequest.location->clientMaxBodySize;
		else
			clientMaxBodySize = client->server->config->clientMaxBodySize;
		if ( clientMaxBodySize )
		{
			size_t contentLength( utils::conv::strTo< size_t >( headers["Content-Length"] ) );
			if ( contentLength > clientMaxBodySize )
				throw http::Exception( 413 );
		}
	}
}
