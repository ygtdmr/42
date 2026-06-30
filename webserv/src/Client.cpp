/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 04:03:51 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 13:01:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Client.hpp"

Client::Client( ServerConfig const& serverConfig )
	: request( new HttpRequest() ), response( new HttpResponse() ), serverConfig( serverConfig )
{}

Client::Client( Client const& other )
	: request( new HttpRequest() ), response( new HttpResponse() ), serverConfig( other.serverConfig )
{
	*this = other;
}

Client::~Client()
{
	delete request;
	delete response;
}

Client& Client::operator=( Client const& other )
{
	if ( this != &other )
	{
		address		   = other.address;
		requestBuffer  = other.requestBuffer;
		responseBuffer = other.responseBuffer;
		lastActivity   = other.lastActivity;
		*request	   = *other.request;
		*response	   = *other.response;
	}
	return *this;
}

bool Client::parseRequest( void )
{
	int short& errorCode( request->errorCode );
	lastActivity = std::time( 0 );
	if ( requestBuffer.size() > serverConfig.clientMaxBodySize )
		errorCode = 413;
	if ( !errorCode && ( request->parseState == STATE_HEADERS ) )
	{
		std::string end( "\r\n\r\n" );
		size_t		posEnd( requestBuffer.find( end ) );
		if ( posEnd == std::string::npos )
		{
			end	   = "\n\n";
			posEnd = requestBuffer.find( end );
		}
		if ( posEnd != std::string::npos )
		{
			request->parseHeaders( requestBuffer.substr( 0, posEnd ) );
			requestBuffer = requestBuffer.substr( posEnd + end.size() );
		}
	}
	if ( !errorCode && ( request->parseState == STATE_BODY ) )
		request->parseBody( requestBuffer );
	if ( !errorCode && ( request->parseState == STATE_CHUNKED ) )
		request->unchunkBody( requestBuffer );
	if ( !errorCode && ( request->parseState == STATE_VALIDATE ) )
		request->validate( serverConfig );
	return errorCode || ( request->parseState == STATE_DONE );
}

void Client::clear( void )
{
	*request  = HttpRequest();
	*response = HttpResponse();
	requestBuffer.clear();
	responseBuffer.clear();
	requestBuffer  = "";
	responseBuffer = "";
	lastActivity   = std::time( 0 );
}
