/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:38:51 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/24 13:46:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <algorithm>
#include "Response.hpp"
#include "Tools.hpp"

Response::Response( Client& client )
: client_( client )
{
	sendData_ = new std::string();
}

Response::Response( Response const& other )
: client_( other.client_ )
{
	*this = other;
}

Response::~Response()
{
	delete sendData_;
}

Response	&Response::operator=( Response const& other )
{
	if ( this != &other )
	{
		client_ = other.client_;
		*sendData_ = *other.sendData_;
	}
	return ( *this );
}

void	Response::processError( int statusCode )
{
	std::stringstream	ssBody;
	std::stringstream	ssHeader;
	std::ifstream		ifs;
	bool				autoGenerate;

	autoGenerate = ( client_.serverConfig.errorPages.find( statusCode ) ==  client_.serverConfig.errorPages.end() );
	if ( !autoGenerate )
	{
		std::string	path( client_.serverConfig.errorPages.find( statusCode )->second );
		ifs.open( path.c_str(), std::ios::in );
		autoGenerate = !ifs.is_open();
	}
	if ( autoGenerate )
	{
		ssBody << "<html>" << std::endl;
		ssBody << "<head><title>" << statusCode << " " << getReasonPhrase( statusCode ) << "</title></head>" << std::endl;
		ssBody << "<body>" << std::endl;
		ssBody << "<center><h1>" << statusCode << " " << getReasonPhrase( statusCode ) << "</h1></center>" << std::endl;
		ssBody << "</body>" << std::endl;
		ssBody << "</html>" << std::endl;
	}
	else
	{
		std::string	line;

		while ( std::getline( ifs, line ) )
			ssBody << line;
	}
	ssHeader << "Content-Length: " << ssBody.str().size() << "\r\n";
	ssHeader << "Content-Type: text/html" << "\r\n";
	ssHeader << "Connection: close" << "\r\n\r\n";
	*sendData_ = ssHeader.str() + ssBody.str();
}

int	Response::processLocation( LocationConfig const& location )
{
	std::stringstream	ssBody;
	std::stringstream	ssHeader;
	std::ifstream		ifs;
	std::string			file;
	std::string			fileExt;

	file = location.root + "/" + location.index;
	ifs.open( file.c_str(), std::ios::in );
	if ( !ifs.is_open() && location.autoindex )
	{
		file = location.root + "/index.html";
		ifs.open( file.c_str(), std::ios::in );
	}
	if ( !ifs.is_open() )
	{
		processError( 404 );
		return ( 404 );
	}
	if ( client_.method == "GET" )
	{
		std::string	line;

		while ( std::getline( ifs, line ) )
			ssBody << line << std::endl;
	}
	else
	{
		processError( 404 );
		return ( 404 );
	}
	if ( file.find( '.' ) != std::string::npos )
		fileExt = file.substr( file.find( '.' ) );
	ssHeader << "Content-Length: " << ssBody.str().size() << "\r\n";
	ssHeader << "Content-Type: " << getContentType( fileExt ) << "\r\n";
	ssHeader << "Connection: close" << "\r\n\r\n";
	*sendData_ = ssHeader.str() + ssBody.str();
	return ( 200 );
}

std::string const	&Response::process( void )
{
	std::stringstream	sendRequestFirstLine;
	short int			statusCode( 0 );

	if ( client_.status & CLIENT_STATUS_ERROR_BR )
		statusCode = 400;
	else if ( client_.status & CLIENT_STATUS_ERROR_CTL )
		statusCode = 413;
	else if ( client_.status & CLIENT_STATUS_ERROR_HTTP_V )
		statusCode = 505;
	else if ( client_.serverConfig.locations.find( client_.requestUri ) == client_.serverConfig.locations.end() )
		statusCode = 404;
	if ( statusCode > 0 )
		processError( statusCode );
	else
		statusCode = processLocation( client_.serverConfig.locations.find( client_.requestUri )->second );
	sendRequestFirstLine << "HTTP/1.1 " << statusCode << " " << getReasonPhrase( statusCode ) << "\r\n";
	sendData_->insert(0, sendRequestFirstLine.str());
	return ( *sendData_ );
}
