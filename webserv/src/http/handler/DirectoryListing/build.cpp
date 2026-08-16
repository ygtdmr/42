/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:55:12 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:55:13 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <dirent.h>
#include <sstream>
#include "http/handler/DirectoryListing.hpp"
#include "http/Client.hpp"
#include "utils/conv.hpp"

void webserv::http::handler::DirectoryListing::build( void )
{
	DIR* dir( opendir( realPath.c_str() ) );
	std::stringstream ss;
	ss << "<html>" << std::endl;
	ss << "<head><title>Index of " << client->httpRequest.uriPath << "</title></head>" << std::endl;
	ss << "<body>" << std::endl;
	ss << "<h1>Index of " << client->httpRequest.uriPath << "</h1>" << std::endl;
	ss << "<hr><pre>" << std::endl;
	if ( dir )
	{
		dirent* entry;
		while ( ( entry = readdir( dir ) ) )
		{
			std::string linkPath( client->httpRequest.uriPath );
			std::string name( entry->d_name );
			if ( name == "." )
				continue;
			if ( entry->d_type == DT_DIR )
				name += '/';
			if ( *( linkPath.end() - 1 ) != '/' )
				linkPath += '/';
			linkPath += name;
			ss << "<a href=\"" << linkPath << "\">" << name << "</a>\n";
		}
		closedir( dir );
	}
	ss << "</pre><hr></body>" << std::endl;
	ss << "</html>";
	body					  = ss.str();
	headers.set("Content-Type", "text/html");
	headers.set("Content-Length", utils::conv::toStr< size_t >( body.size()));
	status					  = 200;
	client->deliverData		  = getFirstLine() + headers.str();
	if ( client->httpRequest.method != "HEAD" )
		client->deliverData += body;
	currentState = DONE;
}
