/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseChunkedBody.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 11:33:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/unchunkBody.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseChunkedBody( void )
{
	chunkedBuffer += client->receiveData;
	client->receiveData.clear();
	client->httpRequest.body += unchunkBody( chunkedBuffer );
	checkMaxBodySize();
	if (chunkedBuffer.find("0\r\n\r\n") == 0)
	{
		currentState = DONE;
	}
}
