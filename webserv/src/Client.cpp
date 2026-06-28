/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 04:03:51 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 20:15:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
	if ( requestBuffer.size() > serverConfig.clientMaxBodySize )
	{
		request->errorCode = 413;
		return true;
	}
	lastActivity = std::time( 0 );
	if ( request->parseState == STATE_FIRSTLINE )
	{
		if ( requestBuffer.find( "\r\n" ) != std::string::npos )
		{
			request->parseFirstLine( requestBuffer.substr( 0, requestBuffer.find( "\r\n" ) ) );
			requestBuffer = requestBuffer.substr( requestBuffer.find( "\r\n" ) + 1 );
		}
	}
	if ( request->parseState == STATE_HEADERS )
	{
		if ( requestBuffer.find( "\r\n" ) != std::string::npos )
		{
			request->parseHeaders( requestBuffer.substr( 0, requestBuffer.find( "\r\n" ) ) );
			requestBuffer = requestBuffer.substr( requestBuffer.find( "\r\n" ) + 1 );
		}
	}
	if ( request->parseState == STATE_BODY )
		request->parseBody( requestBuffer );
	if ( request->parseState == STATE_CHUNKED )
		request->unchunkBody( requestBuffer );
	return request->errorCode || ( request->parseState == STATE_DONE );
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
