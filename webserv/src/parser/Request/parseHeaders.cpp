/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 23:11:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../inc/hpp/utils/conv.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseHeaders( void )
{
	client->httpRequest.body += client->receiveData;
	client->receiveData.clear();
	client->receiveData = "";
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
	if (!headers["Content-Length"].empty())
		contentLength_ = utils::conv::strTo< size_t >( headers["Content-Length"] );
	if ( client->httpRequest.version == "HTTP/1.1" )
	{
		if ( headers["Host"].empty() )
			throw http::Exception( 400 );
		if ( headers["Transfer-Encoding"] == "chunked" )
		{
			chunkedBuffer = client->httpRequest.body;
			client->httpRequest.body.clear();
			client->httpRequest.body = "";
			currentState = CHUNKED_BODY;
		}
		else if ( contentLength_ > 0 )
			currentState = BODY;
		else
		{
			client->httpRequest.body.clear();
			client->httpRequest.body = "";
			currentState = DONE;
		}
	}
	else if ( contentLength_ > 0 )
		currentState = BODY;
	else
	{
		client->httpRequest.body.clear();
		client->httpRequest.body = "";
		currentState = DONE;
	}
	if ( contentLength_ > 0 )
	{
		size_t clientMaxBodySize( 0 );
		if ( client->httpRequest.location )
			clientMaxBodySize = client->httpRequest.location->clientMaxBodySize;
		else
			clientMaxBodySize = client->server->config->clientMaxBodySize;
		if ( ( clientMaxBodySize > 0 ) && ( contentLength_ > clientMaxBodySize ) )
			throw http::Exception( 413 );
	}
}
