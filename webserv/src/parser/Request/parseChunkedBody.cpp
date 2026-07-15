/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseChunkedBody.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 21:46:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/unchunkBody.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseChunkedBody( void )
{
	chunkedBuffer += client->receiveData;
	client->receiveData.clear();
	client->receiveData = "";

	std::string const& unchunkData(unchunkBody( chunkedBuffer ));
	client->httpRequest.body = unchunkData;
	client->httpRequest.bodySize += client->httpRequest.body.size();
}
