/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseStateLocation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:47:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 14:27:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/config/Exception.hpp"
#include "../../../inc/hpp/parser/Config.hpp"

static bool isDuplicate( std::vector< webserv::config::Location > const& locations,
						 std::string const&								 uriPath )
{
	std::vector< webserv::config::Location >::const_iterator it( locations.begin() );
	while ( it != locations.end() )
	{
		if ( it->uriPath == uriPath )
			return true;
		it++;
	}
	return false;
}

void webserv::parser::Config::parseStateLocation( config::Server& server, std::string const& path )
{
	std::string		 word;
	config::Location location = webserv::config::Location();
	location.uriPath		  = path;

	if ( ( raw_ >> word ) && ( word != "{" ) )
		throw config::Exception( servers_.size(), path ) << "invalid location syntax: " << word;
	else if ( !isValidPath( path, true ) )
		throw config::Exception( servers_.size(), path ) << "invalid location path: " << word;
	while ( raw_ >> word )
	{
		if ( word == "}" )
		{
			if ( !key_.empty() )
				throw config::Exception( servers_.size(), path ) << "missing semicolon: " << key_;
			if ( !isDuplicate( server.locations, path ) )
				server.locations.push_back( location );
			else
				throw config::Exception( servers_.size(), path ) << "duplicate location: " << path;
			return;
		}
		else if ( word == ";" )
		{
			validateLocation( path );
			putDataLocation( location );
			key_ = "";
			values_.clear();
		}
		else if ( key_.empty() )
			key_ = word;
		else
			values_.push_back( word );
	}
}
