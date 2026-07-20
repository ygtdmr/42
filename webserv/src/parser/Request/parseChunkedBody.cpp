/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseChunkedBody.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Exception.hpp"
#include "http/Client.hpp"
#include "parser/Request.hpp"
#include "parser/unchunkBody.hpp"
#include "utils/str.hpp"

void webserv::parser::Request::parseChunkedBody( void )
{
	chunkedBuffer += client->receiveData;
	std::string const& unchunkData(unchunkBody( chunkedBuffer ));
	client->httpRequest.body += unchunkData;
	client->httpRequest.bodySize += unchunkData.size();
	checkMaxBodySize();
	if ( chunkedBuffer.find( "0\r\n\r\n" ) == 0 )
		currentState = DONE;
}
