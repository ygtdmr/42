/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseChunkedBody.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 19:24:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/parser/unchunkBody.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseChunkedBody( void )
{
	client->httpRequest.body += unchunkBody( client->receiveData );
	bool isChunkedBodyDone( utils::str::has( client->receiveData, "0\r\n" ) ||
							utils::str::has( client->receiveData, "0\n" ) );
	if ( isChunkedBodyDone )
		currentState = DONE;
}
