/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:59:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/28 14:31:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HttpResponse.hpp"
#include <dirent.h>
#include <fstream>
#include <sstream>

#define READ_BUFFER_SIZE 8

HttpResponse::HttpResponse( void ) : statusCode_( 0 ) {}

HttpResponse::HttpResponse( HttpResponse const& other )
{
	*this = other;
}

HttpResponse::~HttpResponse() {}

HttpResponse& HttpResponse::operator=( HttpResponse const& other )
{
	if ( this != &other )
	{
		statusCode_ = other.statusCode_;
		headers_	= other.headers_;
		body_		= other.body_;
	}
	return *this;
}

void HttpResponse::handleGet( LocationConfig const& locationConfig, std::string const& uriPath )
{
	char		  readBuffer[READ_BUFFER_SIZE];
	std::string	  extension;
	std::string	  fullPath( locationConfig.root + uriPath );
	std::ifstream ifs;

	if ( ServerConfig::isDir( fullPath ) )
		fullPath += ServerConfig::indexFileName( locationConfig );
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
	statusCode_				   = 200;
}

void HttpResponse::handlePost( LocationConfig const& locationConfig, std::string const& uriPath )
{
	( void )locationConfig;
	( void )uriPath;
}

void HttpResponse::handleDelete( LocationConfig const& locationConfig, std::string const& uriPath )
{
	( void )locationConfig;
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
	if ( code == 400 || code == 501 || code == 505 )
		headers_["Connection"] = "close";
	statusCode_ = code;
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
			if ( name == "." || name == ".." )
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
	statusCode_				   = 200;
}

std::string HttpResponse::build( std::string& connection )
{
	std::stringstream ss;
	ss << "HTTP/1.1 " << statusCode_ << " " << getReasonPhrase( statusCode_ ) << "\r\n";
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

char const* HttpResponse::getReasonPhrase( int statusCode )
{
	switch ( statusCode )
	{
		case 200:
			return "OK";
		case 400:
			return "Bad Request";
		case 404:
			return "Not Found";
		case 405:
			return "Method Not Allowed";
		case 413:
			return "Content Too Large";
		case 500:
			return "Internal Server Error";
		case 501:
			return "Not Implemented";
		case 505:
			return "HTTP Version Not Supported";
	}
	return ( 0 );
}

char const* HttpResponse::getContentType( std::string const& ext )
{
	if ( ext == ".html" || ext == ".htm" )
		return "text/html";
	else if ( ext == ".css" )
		return "text/css";
	else if ( ext == ".js" )
		return "application/javascript";
	else if ( ext == ".txt" )
		return "text/plain";
	else if ( ext == ".jpg" || ext == ".jpeg" )
		return "image/jpeg";
	else if ( ext == ".png" )
		return "image/png";
	else if ( ext == ".gif" )
		return "image/gif";
	else if ( ext == ".bmp" )
		return "image/bmp";
	else if ( ext == ".ico" )
		return "image/x-icon";
	else if ( ext == ".svg" )
		return "image/svg+xml";
	else if ( ext == ".json" )
		return "application/json";
	else if ( ext == ".xml" )
		return "application/xml";
	else if ( ext == ".pdf" )
		return "application/pdf";
	else if ( ext == ".zip" )
		return "application/zip";
	return "application/octet-stream";
}
