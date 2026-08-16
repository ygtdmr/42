/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMaxBodySize.cpp                               :+:      :+:    :+:   */
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

void webserv::parser::Request::checkMaxBodySize( void )
{
	size_t clientMaxBodySize( client->httpRequest.location->clientMaxBodySize );
	if ( !clientMaxBodySize )
		clientMaxBodySize = client->server->config->clientMaxBodySize;
	if ( !clientMaxBodySize )
		return;
	if ( client->httpRequest.bodySize > clientMaxBodySize )
		throw http::Exception( 413 );
}
