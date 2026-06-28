/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:59:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 20:15:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <sstream>
#include "../include/HttpRequest.hpp"

HttpRequest::HttpRequest( void ) : parseState( 0 ), errorCode( 0 ) {}

HttpRequest::HttpRequest( HttpRequest const& other )
{
	*this = other;
}

HttpRequest::~HttpRequest() {}

HttpRequest& HttpRequest::operator=( HttpRequest const& other )
{
	if ( this != &other )
	{
		method	   = other.method;
		uri		   = other.uri;
		version	   = other.version;
		headers	   = other.headers;
		body	   = other.body;
		parseState = other.parseState;
	}
	return *this;
}

void HttpRequest::parseFirstLine( std::string const& line )
{
	std::stringstream ss( line );

	ss >> method;
	ss >> uri;
	ss >> version;
	if ( method.empty() || uri.empty() || version.empty() )
		errorCode = 400;
	else if ( method != "GET" && method != "POST" && method != "DELETE" )
		errorCode = 405;
	else if ( *uri.begin() != '/' )
		errorCode = 400;
	else if ( version != "HTTP/1.1" )
		errorCode = 505;
	parseState = STATE_HEADERS;
}

void HttpRequest::parseHeaders( std::string const& data )
{
	char const*		  whitespace( " \t\r\n" );
	std::stringstream ss( data );
	std::string		  line;

	while ( std::getline( ss, line ) )
	{
		if ( line.empty() )
			break;
		if ( line.find( ':' ) != std::string::npos )
		{
			std::string key;
			std::string value;

			key = line.substr( 0, line.find( ':' ) );
			if ( key.empty() )
				errorCode = 400;
			else
			{
				value = line.substr( line.find( ':' ) + 1 );
				size_t start( value.find_first_not_of( whitespace ) );
				size_t end( value.find_last_not_of( whitespace ) );
				if ( start != std::string::npos )
					value = value.substr( start, end - start + 1 );
				headers[key] = value;
			}
		}
		else
			errorCode = 400;
		if ( errorCode )
			return;
	}
	if ( headers.find( "Transfer-Encoding" ) != headers.end() )
		parseIsBodyChunked();
	else if ( headers.find( "Content-Length" ) != headers.end() )
		parseContentLength();
	parseState = STATE_BODY;
}

void HttpRequest::parseBody( std::string const& data )
{
	if ( isBodyChunked )
	{
		if ( ( data.size() >= 5 ) && ( data.substr( data.size() - 5 ) == "0\r\n\r\n" ) )
			parseState = STATE_CHUNKED;
	}
	else if ( contentLength )
	{
		if ( data.size() >= contentLength )
			parseState = STATE_DONE;
	}
	else
		parseState = STATE_DONE;
}

void HttpRequest::unchunkBody( std::string& data )
{
	std::string cleanBody;
	std::size_t pos( 0 );

	while ( pos < data.size() )
	{
		std::size_t nextLineEnd( data.find( "\r\n", pos ) );

		if ( nextLineEnd == std::string::npos )
			break;

		std::string		  hexSize( data.substr( pos, nextLineEnd - pos ) );
		std::size_t		  chunkSize;
		std::stringstream ss;

		ss << std::hex << hexSize;
		ss >> chunkSize;
		if ( chunkSize == 0 )
			break;
		pos = nextLineEnd + 2;
		if ( pos + chunkSize > data.size() )
			break;
		cleanBody += data.substr( pos, chunkSize );
		pos += chunkSize + 2;
	}
	data	   = cleanBody;
	parseState = STATE_DONE;
}

void HttpRequest::parseIsBodyChunked( void )
{
	if ( headers["Transfer-Encoding"] == "chunked" )
		isBodyChunked = true;
	else
		errorCode = 501;
}

void HttpRequest::parseContentLength( void )
{
	char const* digits( "0123456789" );

	if ( headers["Content-Length"].find_first_not_of( digits ) == std::string::npos )
		std::stringstream( headers["Content-Length"] ) >> contentLength;
	else
		errorCode = 400;
}
