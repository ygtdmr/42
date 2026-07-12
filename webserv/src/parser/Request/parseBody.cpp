/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseBody.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 11:33:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/conv.hpp"

void webserv::parser::Request::parseBody( void )
{
	client->httpRequest.body += client->receiveData;
	client->receiveData.clear();
	checkMaxBodySize();
	size_t contentLength( utils::conv::strTo< size_t >( client->httpRequest.headers["Content-Length"] ) );
	if ( client->httpRequest.body.size() >= contentLength )
	{
		client->httpRequest.body = client->httpRequest.body.substr(0, contentLength);
		currentState = DONE;
	}
}
