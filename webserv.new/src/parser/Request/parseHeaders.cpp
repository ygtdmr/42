/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 19:24:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../inc/hpp/utils/map.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseHeaders( void )
{
	if ( !( utils::str::has( client->receiveData, "\r\n\r\n" ) ||
			utils::str::has( client->receiveData, "\n\n" ) ) )
		return;
	std::map< std::string, std::string >& headers( client->httpRequest.headers );
	headers = headersToMap( client->receiveData );
	if ( client->httpRequest.version == "HTTP/1.1" )
	{
		if ( utils::map::has< std::string, std::string >( headers, "Host" ) && headers["Host"].empty() )
			throw http::Exception( 400 );
		if ( utils::map::isEq< std::string, std::string >( headers, "Transfer-Encoding", "chunked" ) )
			currentState = CHUNKED_BODY;
	}
	else if ( utils::map::has< std::string, std::string >( headers, "Content-Length" ) )
		currentState = BODY;
	else
		currentState = DONE;
}
