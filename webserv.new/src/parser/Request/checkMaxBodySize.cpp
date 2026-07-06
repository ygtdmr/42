/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMaxBodySize.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 19:25:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Exception.hpp"
#include "../../../inc/hpp/parser/Request.hpp"

void webserv::parser::Request::checkMaxBodySize( void )
{
	size_t clientMaxBodySize( client->httpRequest.location->clientMaxBodySize );
	if ( !clientMaxBodySize )
		clientMaxBodySize = client->server->config->clientMaxBodySize;
	if ( !clientMaxBodySize )
		return;
	if ( client->receiveData.size() > clientMaxBodySize )
		throw http::Exception( 413 );
}
