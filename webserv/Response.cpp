/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:38:51 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/25 20:06:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <algorithm>
#include <sys/stat.h>
#include <dirent.h>
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
		statusCode = other.statusCode;
	}
	return ( *this );
}

LocationConfig const	*Response::findLocation( std::string const& path )
{
	std::map<std::string, LocationConfig>::const_iterator	it( client_.serverConfig.locations.begin() );
	LocationConfig	const *location( 0 );

	while ( it != client_.serverConfig.locations.end() )
	{
		if ( path.find( it->first ) == 0 )
		{
			if ( !location || ( it->first.size() > path.size() ) )
				location = &it->second;
		}
		it++;
	}
	return ( location );
}

void	Response::processHeader( size_t cl, std::string const& ext )
{
	std::stringstream	ssHeader;

	ssHeader << "Content-Length: " << cl << "\r\n";
	ssHeader << "Content-Type: " << getContentType( ext ) << "\r\n";
	if ( client_.headers.find("Connection") != client_.headers.end() )
		ssHeader << "Connection: " << client_.headers["Connection"] << "\r\n\r\n";
	else
		ssHeader << "Connection: close" << "\r\n\r\n";
	*sendData_ += ssHeader.str();
}

int	Response::processError( int statusCode )
{
	std::stringstream	ssBody;
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
	processHeader( ssBody.str().size(), ".html" );
	*sendData_ += ssBody.str();
	return ( statusCode );
}

int	Response::processRoute( void )
{
	std::stringstream		ssBody;
	std::ifstream			ifs;
	std::string				fileExt;
	LocationConfig const	*location;
	std::string				path( client_.requestUri );
	struct stat				pathStat;
	
	if ( path.find('?') != std::string::npos )
		path = path.substr( 0, path.find( '?' ) );
	location = findLocation( path );
	if ( !location )
		return ( processError( 404 ) );
	if ( path.find( '.' ) != std::string::npos )
		fileExt = path.substr( path.find( '.' ) );
	path.insert( 0, location->root );
	if ( stat(path.c_str(), &pathStat) != 0 )
		return ( processError( 404 ) );
	if ( S_ISDIR( pathStat.st_mode ) )
	{
		std::string	index( location->index );

		if ( index.empty() )
			index = "index.html";
		fileExt = index.substr( index.find( '.' ) );
		ifs.open( ( path + '/' + index ).c_str(), std::ios::in );
		if ( !ifs.is_open() && location->autoindex )
			return ( processDirectoryList( path ) );
	}
	else
		ifs.open( path.c_str(), std::ios::in );
	if ( !ifs.is_open() )
		return ( processError( 404 ) );
	if ( client_.method == "GET" )
	{
		std::string	line;

		while ( std::getline( ifs, line ) )
			ssBody << line << std::endl;
	}
	else
		return ( processError( 404 ) );
	processHeader( ssBody.str().size(), fileExt );
	*sendData_ += ssBody.str();
	return ( 200 );
}

int	Response::processDirectoryList( std::string const& dirPath )
{
	std::stringstream		ssBody;
	std::string				requestPath( client_.requestUri );
	DIR						*dir( opendir( dirPath.c_str() ) );
	
	if ( requestPath.find( '?' ) != std::string::npos )
		requestPath = requestPath.substr( 0, requestPath.find( '?' ) );
	ssBody << "<html>" << std::endl;
	ssBody << "<head><title>Index of " << requestPath << "</title></head>" << std::endl;
	ssBody << "<body>" << std::endl;
	ssBody << "<h1>Index of " << requestPath << "</h1>" << std::endl;
	ssBody << "<ul>" << std::endl;
	if ( dir )
	{
		struct dirent*	entry;

		while ( ( entry = readdir(dir) ) )
		{
			std::string	linkPath( requestPath );
			std::string	name( entry->d_name );

			if ( name == "." )
				continue ;
			if ( linkPath.empty() || *( linkPath.end() - 1 ) != '/' )
				linkPath += '/';
			linkPath += name;
			ssBody << "<li><a href=\"" << linkPath << "\">" << name << "</a></li>\n";
		}
	}
	ssBody << "</ul></body>" << std::endl;
	ssBody << "</html>" << std::endl;
	closedir( dir );
	processHeader( ssBody.str().size(), ".html" );
	*sendData_ += ssBody.str();
	return (200);
}

std::string const	&Response::process( void )
{
	std::stringstream	sendRequestFirstLine;

	statusCode = 0;
	if ( client_.status & CLIENT_STATUS_ERROR_BR )
		statusCode = 400;
	else if ( client_.status & CLIENT_STATUS_ERROR_CTL )
		statusCode = 413;
	else if ( client_.status & CLIENT_STATUS_ERROR_HTTP_V )
		statusCode = 505;
	if ( statusCode > 0 )
		processError( statusCode );
	else
		statusCode = processRoute();
	sendRequestFirstLine << "HTTP/1.1 " << statusCode << " " << getReasonPhrase( statusCode ) << "\r\n";
	sendData_->insert(0, sendRequestFirstLine.str());
	return ( *sendData_ );
}
