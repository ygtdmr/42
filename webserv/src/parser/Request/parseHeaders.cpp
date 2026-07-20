/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Exception.hpp"
#include "http/Client.hpp"
#include "http/Headers.hpp"
#include "parser/Request.hpp"
#include "utils/conv.hpp"
#include "utils/str.hpp"

void webserv::parser::Request::parseHeaders( void )
{
	client->httpRequest.body += client->receiveData;
	if ( !( utils::str::has( client->httpRequest.body, "\r\n\r\n" ) ||
			utils::str::has( client->httpRequest.body, "\n\n" ) ) )
		return;
	http::Headers& headers( client->httpRequest.headers );
	try
	{
		headers = http::Headers(client->httpRequest.body, true);
	}
	catch ( std::exception const& _ )
	{
		throw http::Exception( 400 );
	}
	contentLength_ = utils::conv::strTo< size_t >( headers.get("Content-Length") );
	if ( client->httpRequest.version == "HTTP/1.1" )
	{
		if ( headers.get("Host").empty() )
			throw http::Exception( 400 );
		if ( headers.match("Transfer-Encoding", "chunked") )
			currentState = CHUNKED_BODY;
		else if ( contentLength_ > 0 )
			currentState = BODY;
		else
			currentState = DONE;
		client->receiveData = client->httpRequest.body;
		client->httpRequest.body.clear();
		client->httpRequest.body = "";
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
