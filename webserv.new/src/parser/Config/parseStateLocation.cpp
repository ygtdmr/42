/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseStateLocation.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:47:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:14:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::parseStateLocation( config::Server& server, std::string const& path )
{
	std::string		 word;
	config::Location location = webserv::config::Location();

	if ( ( ( *raw_ ) >> word ) && ( word != "{" ) )
		throw config::Exception( server, path ) << "invalid location syntax: " << word;
	else if ( !isValidPath( path ) )
		throw config::Exception( server, path ) << "invalid location path: " << word;
	while ( ( *raw_ ) >> word )
	{
		if ( word == "}" )
		{
			if ( server.locations.find( path ) == server.locations.end() )
				server.locations.insert( std::make_pair( path, location ) );
			else
				throw config::Exception( server, path ) << "duplicate location: " << path;
			return;
		}
		else if ( word == ";" )
		{
			validateLocation( server, path );
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
