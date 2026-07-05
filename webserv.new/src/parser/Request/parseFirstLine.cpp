/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseFirstLine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 14:22:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <sstream>
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
	if ( !utils::str::has( *receiveData, "\n" ) )
		return;
	std::stringstream ss( *receiveData );
	ss >> request->method;
	ss >> request->uri;
	ss >> request->version;
	if ( request->method.empty() || request->uri.empty() || request->version.empty() )
		throw std::exception();
	else if ( request->uri[0] != '/' )
		throw std::exception();
	else if ( ( request->uri != "HTTP/1.0" ) && ( request->uri != "HTTP/1.1" ) )
		throw std::exception();
	request->uriPath = filterQuery( request->uri );
	if ( utils::str::has( *receiveData, "\r\n" ) )
		utils::str::skip( *receiveData, "\r\n" );
	else if ( utils::str::has( *receiveData, "\n" ) )
		utils::str::skip( *receiveData, "\n" );
	currentState = HEADERS;
}
