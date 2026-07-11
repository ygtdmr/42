/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setupEnv.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 14:55:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/utils/str.hpp"

static char* newValue( std::string const& key, std::string const& value )
{
	std::string str( key + "=" + value );
	char*		cStr( new char[str.size() + 1] );
	std::copy( str.begin(), str.end(), cStr );
	cStr[str.size()] = 0;
	return cStr;
}

void webserv::http::handler::Cgi::setupEnv( void )
{
	env_.push_back( newValue( "REDIRECT_STATUS", "200" ) );
	env_.push_back( newValue( "GATEWAY_INTERFACE", "CGI/1.1" ) );
	env_.push_back( newValue( "REQUEST_METHOD", client->httpRequest.method ) );
	env_.push_back( newValue( "REQUEST_URI", client->httpRequest.uri ) );
	env_.push_back( newValue( "QUERY_STRING", utils::str::crop( client->httpRequest.uri, "?" ) ) );
	env_.push_back( newValue( "SERVER_PROTOCOL", client->httpRequest.version ) );
	env_.push_back( newValue( "PATH_INFO", client->httpRequest.uriPath ) );
	env_.push_back( newValue( "SCRIPT_NAME", client->httpRequest.uriPath ) );
	env_.push_back( newValue( "SCRIPT_FILENAME", realPath ) );
	if ( !client->httpRequest.headers["Content-Length"].empty() )
		env_.push_back( newValue( "CONTENT_LENGTH", client->httpRequest.headers["Content-Length"] ) );
	if ( !client->httpRequest.headers["Content-Type"].empty() )
		env_.push_back( newValue( "CONTENT_TYPE", client->httpRequest.headers["Content-Type"] ) );
	if ( !client->httpRequest.headers["Host"].empty() )
		env_.push_back( newValue( "HTTP_HOST", client->httpRequest.headers["Host"] ) );
	env_.push_back( 0 );
}
