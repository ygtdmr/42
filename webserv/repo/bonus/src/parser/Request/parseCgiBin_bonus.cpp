/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseCgiBin_bonus.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:14:50 by yidemir           #+#    #+#             */
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
	std::map<std::string, std::string>::const_iterator	it(client->httpRequest.location->cgi.begin());
	while (it != client->httpRequest.location->cgi.end())
	{
		std::string path( client->httpRequest.uriPath );
		std::string extension( it->first );
		utils::str::skip( path, extension.c_str() );
		if (path.empty())
		{
			client->httpRequest.cgiBin = it->second;
			break;
		}
		it++;
	}
}
