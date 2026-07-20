/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFirstLine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "http/Exception.hpp"
#include "http/Client.hpp"
#include "parser/Request.hpp"
#include "utils/str.hpp"

static bool isSafeUriPath( std::string const& uriPath )
{
	std::vector< std::string > segments;
	std::stringstream		   ss( uriPath );
	std::string				   segment;

	while ( std::getline( ss, segment, '/' ) )
	{
		if ( segment.empty() || segment == "." )
			continue;
		if ( segment == ".." )
		{
			if ( !segments.empty() )
				segments.pop_back();
			else
				return false;
		}
		else
			segments.push_back( segment );
	}
	return true;
}

static std::string filterQuery( std::string& uri )
{
	if ( webserv::utils::str::has( uri, "?" ) )
		uri = uri.substr( 0, uri.find( "?" ) );
	while ( webserv::utils::str::has( uri, "//" ) )
		uri.replace( uri.find( "//" ), 2, "/" );
	return uri;
}

void webserv::parser::Request::parseFirstLine( void )
{
	client->httpRequest.body += client->receiveData;
	client->receiveData.clear();
	client->receiveData = "";
	if ( !utils::str::has( client->httpRequest.body, "\n" ) )
		return;
	std::string method;
	std::string uri;
	std::string version;

	std::stringstream ss( client->httpRequest.body );
	ss >> method;
	ss >> uri;
	ss >> version;

	if ( method.empty() || uri.empty() || version.empty() )
		throw http::Exception( 400 );
	else if ( uri[0] != '/' )
		throw http::Exception( 400 );
	else if ( ( version != "HTTP/1.0" ) && ( version != "HTTP/1.1" ) )
		throw http::Exception( 400 );
	client->httpRequest.method	= method;
	client->httpRequest.uri		= uri;
	client->httpRequest.version = version;
	client->httpRequest.uriPath = filterQuery( uri );

	if ( !isSafeUriPath( client->httpRequest.uriPath ) )
		throw http::Exception( 404 );
	currentState = LOCATION;
}
