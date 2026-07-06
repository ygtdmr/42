/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:12:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <sstream>
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/http/handler/DirectoryListing.hpp"

void webserv::http::handler::DirectoryListing::build( void )
{
	DIR*			  dir( opendir( realPath.c_str() ) );
	headers["Content-Type"] = "text/html";
	std::stringstream	ss;
	ss << "<html>" << std::endl;
	ss << "<head><title>Index of " << client->httpRequest.uriPath << "</title></head>" << std::endl;
	ss << "<body>" << std::endl;
	ss << "<h1>Index of " << client->httpRequest.uriPath << "</h1>" << std::endl;
	ss << "<ul>" << std::endl;
	if ( dir )
	{
		dirent* entry;
		while ( ( entry = readdir( dir ) ) )
		{
			std::string linkPath( client->httpRequest.uriPath );
			std::string name( entry->d_name );
			if ( name == "." )
				continue;
			if ( linkPath.empty() || *( linkPath.end() - 1 ) != '/' )
				linkPath += '/';
			linkPath += name;
			ss << "<li><a href=\"" << linkPath << "\">" << name << "</a></li>\n";
		}
	}
	ss << "</ul></body>" << std::endl;
	ss << "</html>";
	body = ss.str();
	headers["Content-Length"] = body.size();
	client->deliverData	 = parser::mapToHeaders( headers ) + body;
	currentState = DONE;
}
