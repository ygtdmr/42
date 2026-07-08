/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 17:28:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseHeaders( void )
{
	if ( !( utils::str::has( client->receiveData, "\r\n\r\n" ) ||
			utils::str::has( client->receiveData, "\n\n" ) ) )
		return;
	std::map< std::string, std::string >& headers( client->httpRequest.headers );
	try
	{
		headers = headersToMap( client->receiveData );
	}
	catch ( std::exception const& _ )
	{
		throw http::Exception( 400 );
	}
	if ( client->httpRequest.version == "HTTP/1.1" )
	{
		if ( headers["Host"].empty() )
			throw http::Exception( 400 );
		if ( headers["Transfer-Encoding"] == "chunked" )
			currentState = CHUNKED_BODY;
		else
			currentState = DONE;
	}
	else if ( !headers["Content-Length"].empty() )
		currentState = BODY;
	else
		currentState = DONE;
}
