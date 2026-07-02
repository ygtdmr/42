/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestFirstLine.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:37:15 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 18:08:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/requestFirstLine.hpp"
#include <exception>
#include <sstream>
#include "../../inc/hpp/utils/str.hpp"

void webserv::parser::requestFirstLine( std::string& data, webserv::http::Request& request )
{
	std::stringstream ss( data );
	ss >> request.method;
	ss >> request.uri;
	ss >> request.version;
	if ( request.method.empty() || request.uri.empty() || request.version.empty() )
		throw std::exception();
	else if ( request.uri[0] != '/' )
		throw std::exception();
	else if ( ( request.uri != "HTTP/1.0" ) && ( request.uri != "HTTP/1.1" ) )
		throw std::exception();
	if ( utils::str::has( data, "\r\n" ) )
		utils::str::skip( data, "\r\n" );
	else if ( utils::str::has( data, "\n" ) )
		utils::str::skip( data, "\n" );
}
