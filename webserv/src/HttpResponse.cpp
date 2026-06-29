/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:59:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 10:40:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HttpResponse.hpp"
#include <dirent.h>
#include <fstream>
#include <sstream>
#include "../include/HttpConversion.hpp"

#define READ_BUFFER_SIZE 8

HttpResponse::HttpResponse( void ) : statusCode( 0 ) {}

HttpResponse::HttpResponse( HttpResponse const& other )
{
	*this = other;
}

HttpResponse::~HttpResponse() {}

HttpResponse& HttpResponse::operator=( HttpResponse const& other )
{
	if ( this != &other )
	{
		statusCode = other.statusCode;
		headers_   = other.headers_;
		body_	   = other.body_;
	}
	return *this;
}

void HttpResponse::handleGet( Location const& location, std::string const& uriPath )
{
	char		  readBuffer[READ_BUFFER_SIZE];
	std::string	  extension;
	std::string	  fullPath( location.root + uriPath );
	std::ifstream ifs;

	if ( ServerConfig::isDir( fullPath ) )
		fullPath += '/' + ServerConfig::indexFileName( location );
	ifs.open( fullPath.c_str(), std::ios::binary );
	while ( true )
	{
		ifs.read( readBuffer, sizeof( readBuffer ) - 1 );
		if ( !ifs.gcount() )
			break;
		readBuffer[ifs.gcount()] = 0;
		body_ += readBuffer;
	}
	ifs.close();
	if ( fullPath.find( '.' ) != std::string::npos )
		extension = fullPath.substr( fullPath.find( '.' ) );
	std::stringstream ss;
	ss << body_.size();
	headers_["Content-Length"] = ss.str();
	headers_["Content-Type"]   = getContentType( extension );
	statusCode				   = 200;
}

void HttpResponse::handlePost( Location const& location, std::string const& uriPath )
{
	( void )location;
	( void )uriPath;
}

void HttpResponse::handleDelete( Location const& location, std::string const& uriPath )
{
	( void )location;
	( void )uriPath;
}

void HttpResponse::generateErrorPage( int short code, std::map< int, std::string > const& errorPages )
{
	std::stringstream ss;
	std::ifstream	  ifs;
	bool			  autoGenerate;

	autoGenerate = errorPages.find( code ) == errorPages.end();
	if ( !autoGenerate )
	{
		std::string path( errorPages.find( code )->second );
		ifs.open( path.c_str(), std::ios::binary );
		autoGenerate = !ifs.is_open();
	}
	if ( autoGenerate )
	{
		ss << "<html>" << std::endl;
		ss << "<head><title>" << code << " " << getReasonPhrase( code ) << "</title></head>" << std::endl;
		ss << "<body>" << std::endl;
		ss << "<center><h1>" << code << " " << getReasonPhrase( code ) << "</h1></center>" << std::endl;
		ss << "</body>" << std::endl;
		ss << "</html>";
	}
	else
	{
		char readBuffer[READ_BUFFER_SIZE];
		while ( true )
		{
			ifs.read( readBuffer, sizeof( readBuffer ) - 1 );
			if ( !ifs.gcount() )
				break;
			readBuffer[ifs.gcount()] = 0;
			ss << readBuffer;
		}
		ifs.close();
	}
	body_ = ss.str();
	ss.clear();
	ss.str( "" );
	ss << body_.size();
	headers_["Content-Length"] = ss.str();
	headers_["Content-Type"]   = getContentType( ".html" );
	if ( code == 400 || code == 501 || code == 505 || code == 413 )
		headers_["Connection"] = "close";
	statusCode = code;
}

void HttpResponse::generateDirectoryListing( std::string const& rootPath, std::string const& uriPath )
{
	std::stringstream ss;
	DIR*			  dir( opendir( ( rootPath + '/' + uriPath ).c_str() ) );

	ss << "<html>" << std::endl;
	ss << "<head><title>Index of " << uriPath << "</title></head>" << std::endl;
	ss << "<body>" << std::endl;
	ss << "<h1>Index of " << uriPath << "</h1>" << std::endl;
	ss << "<ul>" << std::endl;
	if ( dir )
	{
		dirent* entry;
		while ( ( entry = readdir( dir ) ) )
		{
			std::string linkPath( uriPath );
			std::string name( entry->d_name );
			if ( name == "." )
				continue;
			if ( linkPath.empty() || *( linkPath.end() - 1 ) != '/' )
				linkPath += '/';
			linkPath += name;
			ss << "<li><a href=\"" << linkPath << "\">" << name << "</a></li>\n";
		}
	}
	ss << "</ul></body>" << std::endl;
	ss << "</html>";
	closedir( dir );
	body_ = ss.str();
	ss.clear();
	ss.str( "" );
	ss << body_.size();
	headers_["Content-Length"] = ss.str();
	headers_["Content-Type"]   = getContentType( ".html" );
	statusCode				   = 200;
}

void HttpResponse::generateRedirect( std::pair< int short, std::string > const& redirect )
{
	headers_["Content-Length"] = "0";
	headers_["Location"]	   = redirect.second;
	statusCode				   = redirect.first;
}

std::string HttpResponse::build( std::string& connection )
{
	std::stringstream ss;
	ss << "HTTP/1.1 " << statusCode << " " << getReasonPhrase( statusCode ) << "\r\n";
	if ( headers_.find( "Connection" ) == headers_.end() )
		headers_["Connection"] = connection;
	else
		connection = headers_["Connection"];
	std::map< std::string, std::string >::iterator it( headers_.begin() );
	while ( it != headers_.end() )
	{
		ss << it->first << ": " << it->second << "\r\n";
		it++;
	}
	ss << "\r\n" << body_ << "\r\n";
	return ss.str();
}
