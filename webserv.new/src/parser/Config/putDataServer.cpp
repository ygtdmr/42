/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putDataServer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:48:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:06:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::putDataServer( config::Server& server ) const
{
	std::stringstream ss( *( values_.begin() ) );

	if ( key_ == "listen" )
		ss >> server.port;
	else if ( key_ == "host" )
		ss >> server.host;
	else if ( key_ == "client_max_body_size" )
	{
		ss >> server.clientMaxBodySize;
		server.clientMaxBodySize *= 1024 * 1024;
	}
	else if ( key_ == "error_page" )
	{
		int										   statusCode;
		std::string								   path( *( values_.end() - 1 ) );
		std::vector< std::string >::const_iterator it( values_.begin() );

		while ( it != values_.end() - 1 )
		{
			ss.clear();
			ss.str( *it );
			ss >> statusCode;
			server.errorPages[statusCode] = path;
			it++;
		}
	}
}
