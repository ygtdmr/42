/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseCgiBin.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:07:57 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Client.hpp"
#include "parser/Request.hpp"
#include "utils/str.hpp"

void webserv::parser::Request::parseCgiBin( void )
{
	if ( client->httpRequest.location->cgi.empty() )
		return;
	std::string path( client->httpRequest.uriPath );
	std::string extension( client->httpRequest.location->cgi.begin()->first );
	utils::str::skip( path, extension.c_str() );
	if (path.empty())
		client->httpRequest.cgiBin = client->httpRequest.location->cgi.begin()->second;
}
