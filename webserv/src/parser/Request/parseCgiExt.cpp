/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseCgiExt.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:07:57 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/16 14:59:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseCgiExt( void )
{
	if ( client->httpRequest.location->cgi.empty() )
		return;
	std::string path( client->httpRequest.uriPath );
	std::string extension( client->httpRequest.location->cgi.begin()->first );
	utils::str::skip( path, extension.c_str() );
	if (path.empty())
		client->httpRequest.cgiExt = extension;
}
