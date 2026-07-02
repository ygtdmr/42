/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printServers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:38:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 09:06:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../../../include/parser/Config.hpp"

static void printCgi( std::map< std::string, std::string > const& cgi )
{
	std::cout << "{";
	std::map< std::string, std::string >::const_iterator it( cgi.begin() );
	while ( it != cgi.end() )
	{
		std::cout << "\"" << it->first << "\":\"" << it->second << "\"";
		it++;
		if ( it != cgi.end() )
			std::cout << ",";
	}
	std::cout << "},";
}

static void printAllowMethods( std::vector< std::string > const& allowMethods )
{
	std::vector< std::string >::const_iterator it( allowMethods.begin() );
	while ( it != allowMethods.end() )
	{
		std::cout << "\"" << *it << "\"";
		it++;
		if ( it != allowMethods.end() )
			std::cout << ",";
	}
}

static void printLocations( std::map< std::string, webserv::config::Location > const& locations )
{
	std::cout << "{";
	std::map< std::string, webserv::config::Location >::const_iterator it( locations.begin() );
	while ( it != locations.end() )
	{
		webserv::config::Location const& location( it->second );
		std::cout << "\"" << it->first << "\":{";

		std::cout << "\"autoindex\":";
		if ( location.autoindex )
			std::cout << "true,";
		else
			std::cout << "false,";
		std::cout << "\"index\":\"" << location.index << "\",";
		std::cout << "\"root\":\"" << location.root << "\",";
		std::cout << "\"clientMaxBodySize\":" << location.clientMaxBodySize << ",";
		std::cout << "\"uploadDir\":\"" << location.uploadDir << "\",";

		std::cout << "\"cgi\":";
		printCgi( location.cgi );

		std::cout << "\"redirect\":{";
		if ( location.redirect.first > 0 )
		{
			std::cout << "\"" << location.redirect.first << "\": \"";
			std::cout << location.redirect.second << "\"";
		}
		std::cout << "},";

		std::cout << "\"allowMethods\":[";
		printAllowMethods( location.allowMethods );
		std::cout << "]";

		std::cout << "}";
		it++;
		if ( it != locations.end() )
			std::cout << ",";
	}
	std::cout << "}";
}

static void printListens( std::vector< std::string > const& listens )
{
	std::cout << "[";
	std::vector< std::string >::const_iterator it( listens.begin() );
	while ( it != listens.end() )
	{
		std::cout << "\"" << *it << "\"";
		it++;
		if ( it != listens.end() )
			std::cout << ",";
	}
	std::cout << "],";
}

static void printServerNames( std::vector< std::string > const& serverNames )
{
	std::cout << "[";
	std::vector< std::string >::const_iterator it( serverNames.begin() );
	while ( it != serverNames.end() )
	{
		std::cout << "\"" << *it << "\"";
		it++;
		if ( it != serverNames.end() )
			std::cout << ",";
	}
	std::cout << "],";
}

static void printErrorPages( std::map< int short, std::string > const& errorPages )
{
	std::cout << "{";
	std::map< int short, std::string >::const_iterator it( errorPages.begin() );
	while ( it != errorPages.end() )
	{
		std::cout << "\"" << it->first << "\":\"" << it->second << "\"";
		it++;
		if ( it != errorPages.end() )
			std::cout << ",";
	}
	std::cout << "},";
}

void webserv::parser::Config::printServers( void ) const
{
	std::vector< config::Server >::const_iterator it( servers_->begin() );
	std::cout << "[";
	while ( it != servers_->end() )
	{
		std::cout << "{";

		std::cout << "\"listens\":";
		printListens( it->listens );

		std::cout << "\"serverNames\":";
		printServerNames( it->serverNames );

		std::cout << "\"root\":\"" << it->root << "\",";
		std::cout << "\"clientMaxBodySize\":" << it->clientMaxBodySize << ",";

		std::cout << "\"errorPages\":";
		printErrorPages( it->errorPages );

		std::cout << "\"locations\":";
		printLocations( it->locations );

		std::cout << "}";

		it++;
		if ( it != servers_->end() )
			std::cout << ",";
	}
	std::cout << "]" << std::endl;
}
