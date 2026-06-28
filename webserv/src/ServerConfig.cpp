/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:59:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 18:02:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ServerConfig.hpp"
#include <errno.h>
#include <sys/stat.h>
#include <fstream>

ServerConfig::ServerConfig( void ) {}

ServerConfig::ServerConfig( ServerConfig const& other )
{
	*this = other;
}

ServerConfig::~ServerConfig() {}

ServerConfig& ServerConfig::operator=( ServerConfig const& other )
{
	if ( this != &other )
	{
		clientMaxBodySize = other.clientMaxBodySize;
		host			  = other.host;
		port			  = other.port;
		errorPages		  = other.errorPages;
		locations		  = other.locations;
	}
	return *this;
}

LocationConfig const* ServerConfig::matchLocationConfig( std::string uri ) const
{
	std::map< std::string, LocationConfig >::const_iterator it( locations.begin() );
	LocationConfig const*									location( 0 );

	uri = uriToPath( uri );
	while ( it != locations.end() )
	{
		if ( uri.find( it->first ) == 0 )
		{
			if ( !location || ( it->first.size() > uri.size() ) )
				location = &it->second;
		}
		it++;
	}
	return location;
}

std::string ServerConfig::uriToPath( std::string const& uri )
{
	if ( uri.find( '?' ) != std::string::npos )
		return uri.substr( 0, uri.find( '?' ) );
	return uri;
}

int short ServerConfig::statusLocationAccess( LocationConfig const& locationConfig,
											  std::string const&	fullPath )
{
	std::ifstream ifs( fullPath.c_str() );
	bool		  isOpen( ifs.is_open() );

	if ( !isOpen )
	{
		if ( errno == EACCES )
			return 403;
		else
			return 404;
	}
	if ( isDir( fullPath ) )
	{
		std::string index( locationConfig.index );
		if ( index.empty() )
			index = "index.html";
		if ( ServerConfig::statusLocationAccess( locationConfig, fullPath + '/' + index ) == 403 )
			return 403;
	}
	ifs.close();
	return 0;
}

bool ServerConfig::isDir( std::string const& path )
{
	struct stat pathStat;

	stat( path.c_str(), &pathStat );
	return S_ISDIR( pathStat.st_mode );
}
