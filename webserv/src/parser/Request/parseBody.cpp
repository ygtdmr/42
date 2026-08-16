/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseBody.cpp                                      :+:      :+:    :+:   */
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
#include "utils/conv.hpp"

void webserv::parser::Request::parseBody( void )
{
	client->httpRequest.body += client->receiveData;
	client->httpRequest.bodySize += client->receiveData.size();
	checkMaxBodySize();
	if ( client->httpRequest.bodySize >= contentLength_ )
		currentState = DONE;
}
