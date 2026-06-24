/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 19:44:52 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/24 09:11:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <sstream>
#include "Client.hpp"

Client::Client( sockaddr_in addr, ServerConfig& serverConfig )
: addr( addr ), serverConfig( serverConfig )
{
	status = 0;
	contentLength_ = 0;
	isContentChunked_ = false;
}

Client::Client( Client const& other )
: serverConfig( other.serverConfig )
{
	*this = other;
}

Client::~Client()
{}

Client	&Client::operator=( Client const& other )
{
	if ( this != &other )
	{
		addr = other.addr;
		headers = other.headers;
		serverConfig = other.serverConfig;
		status = other.status;
		method = other.method;
		requestUri = other.requestUri;
		httpVersion = other.httpVersion;
		rawData_ = other.rawData_;
		contentLength_ = other.contentLength_;
		isContentChunked_ = other.isContentChunked_;
	}
	return ( *this );
}

void	Client::read( char const* buffer, int bytesRead )
{
	if ( ( rawData_.size() + bytesRead ) > serverConfig.clientMaxBodySize )
	{
		status |= CLIENT_STATUS_ERROR_CTL;
		return ;
	}
	rawData_.append( buffer, bytesRead );
	if ( !( status & CLIENT_STATUS_RQ_LINE_OK ) )
		readRequestLine();
	if ( ( status & CLIENT_STATUS_RQ_LINE_OK ) && !( status & CLIENT_STATUS_HEADER_OK ) )
		readHeaders();
	if ( ( status & CLIENT_STATUS_HEADER_OK ) && !( status & CLIENT_STATUS_CONTENT_READ ) )
	{
		if ( headers.find( "Transfer-Encoding" ) != headers.end() )
			isContentChunked_ = ( headers["Transfer-Encoding"] == "chunked" );
		else if ( headers.find( "Content-Length" ) != headers.end() )
			std::stringstream( headers["Content-Length"] ) >> contentLength_;
		status |= CLIENT_STATUS_CONTENT_READ;
	}
	if ( !( status & CLIENT_STATUS_CONTENT_READ ) )
		return ;
	if ( isContentChunked_ )
	{
		if ( rawData_.size() >= 5 && ( rawData_.substr( rawData_.size() - 5 ) == "0\r\n\r\n" ) )
			status = CLIENT_STATUS_READ_OK;
	}
	else if ( contentLength_ > 0 )
	{
		if ( rawData_.size() >= contentLength_ )
			status = CLIENT_STATUS_READ_OK;
	}
	else
		status = CLIENT_STATUS_READ_OK;
}

bool	Client::isReadEnd( void ) const
{
	return ( status & ( CLIENT_STATUS_READ_OK | CLIENT_STATUS_ERROR_BR | CLIENT_STATUS_ERROR_CTL | CLIENT_STATUS_ERROR_HTTP_V ) );
}

const char	*Client::getContent( void ) const
{
	if ( rawData_.find( "\r\n\r\n" ) != std::string::npos)
		return ( rawData_.c_str() + rawData_.find( "\r\n\r\n" ) + 4 );
	else if ( rawData_.find( "\n\n" ) != std::string::npos )
		return ( rawData_.c_str() + rawData_.find( "\n\n" ) + 2 );
	else
		return ( "" );
}

void	Client::readRequestLine( void )
{
	std::stringstream	ss;
	std::string			data;

	if ( rawData_.find( "\r\n" ) != std::string::npos )
		ss.str( rawData_.substr( 0, rawData_.find( "\r\n" ) ) );
	else if ( rawData_.find( '\n' ) != std::string::npos )
		ss.str( rawData_.substr( 0, rawData_.find( '\n' ) ) );
	else
		return ;
	while ( std::getline( ss, data, ' ' ) )
	{
		if ( method.empty() )
			method = data;
		else if ( requestUri.empty() )
			requestUri = data;
		else if ( httpVersion.empty() )
			httpVersion = data;
	}
	if ( ( *requestUri.begin() != '/' ) || method.empty() || httpVersion.empty() )
		status |= CLIENT_STATUS_ERROR_BR;
	else if ( httpVersion != "HTTP/1.1" )
		status |= CLIENT_STATUS_ERROR_HTTP_V;
	else
		status |= CLIENT_STATUS_RQ_LINE_OK;
}

void	Client::readHeaders( void )
{
	std::stringstream	ss;
	std::string			line;

	if ( rawData_.find( "\r\n\r\n" ) != std::string::npos )
		ss.str( rawData_.substr( 0, rawData_.find( "\r\n\r\n" ) ) );
	else if ( rawData_.find( "\n\n" ) != std::string::npos )
		ss.str( rawData_.substr( 0, rawData_.find( "\n\n" ) ) );
	else
		return ;
	std::getline( ss, line );
	while ( std::getline( ss, line ) )
	{
		size_t	colon_pos( line.find(':') );

		if ( colon_pos == std::string::npos )
		{
			status |= CLIENT_STATUS_ERROR_BR;
			return ;
		}
		std::string	key( line.substr( 0, colon_pos ) );
		std::string	value( line.substr( colon_pos + 1 ) );

		if ( !key.empty() && !value.empty() )
			headers[key] = value;
	}
	status |= CLIENT_STATUS_HEADER_OK;
}
