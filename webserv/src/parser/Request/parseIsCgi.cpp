/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseIsCgi.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:07:57 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 15:15:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/str.hpp"

void webserv::parser::Request::parseIsCgi( void )
{
	if ( client->httpRequest.location->cgi.empty() )
		return;
	std::string path( client->httpRequest.uriPath );
	std::string extension( client->httpRequest.location->cgi.begin()->first );
	utils::str::skip( path, extension.c_str() );
	client->httpRequest.isCgi = path.empty();
}
