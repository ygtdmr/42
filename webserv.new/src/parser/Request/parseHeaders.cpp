/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 14:39:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../inc/hpp/utils/map.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseHeaders( void )
{
	if ( !( utils::str::has( *receiveData, "\r\n\r\n" ) || utils::str::has( *receiveData, "\n\n" ) ) )
		return;
	request->headers = headersToMap( *receiveData );
	if ( request->version == "HTTP/1.1" )
	{
		if ( utils::map::has< std::string, std::string >( request->headers, "Host" ) &&
			 request->headers["Host"].empty() )
			throw std::exception();
	}
	else if ( utils::map::isEq< std::string, std::string >(
				  request->headers, "Transfer-Encoding", "chunked" ) )
		currentState = CHUNKED_BODY;
	else if ( utils::map::has< std::string, std::string >( request->headers, "Content-Length" ) )
		currentState = BODY;
	else
		currentState = DONE;
}
