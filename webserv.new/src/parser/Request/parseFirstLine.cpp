/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFirstLine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 19:24:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/str.hpp"

static std::string filterQuery( std::string& uri )
{
	if ( webserv::utils::str::has( uri, "?" ) )
		return uri.substr( 0, uri.find( "?" ) );
	return uri;
}

void webserv::parser::Request::parseFirstLine( void )
{
	if ( !utils::str::has( client->receiveData, "\n" ) )
		return;
	std::string& method( client->httpRequest.method );
	std::string& uri( client->httpRequest.uri );
	std::string& version( client->httpRequest.version );
	std::string& uriPath( client->httpRequest.uriPath );

	std::stringstream ss( client->receiveData );
	ss >> method;
	ss >> uri;
	ss >> version;

	if ( method.empty() || uri.empty() || version.empty() )
		throw http::Exception( 400 );
	else if ( uri[0] != '/' )
		throw http::Exception( 400 );
	else if ( ( uri != "HTTP/1.0" ) && ( uri != "HTTP/1.1" ) )
		throw http::Exception( 400 );

	uriPath = filterQuery( uri );
	if ( utils::str::has( client->receiveData, "\r\n" ) )
		utils::str::skip( client->receiveData, "\r\n" );
	else if ( utils::str::has( client->receiveData, "\n" ) )
		utils::str::skip( client->receiveData, "\n" );
	currentState = LOCATION;
}
