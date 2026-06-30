/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:59:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 10:36:44 by yidemir          ###   ########.fr       */
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

Location const* ServerConfig::matchLocation( std::string uri ) const
{
	std::map< std::string, Location >::const_iterator it( locations.begin() );
	Location const*									  location( 0 );
	std::string										  locationUri;

	uri = uriToPath( uri );
	while ( it != locations.end() )
	{
		if ( uri.find( it->first ) == 0 )
		{
			if ( !location || ( it->first.size() >= locationUri.size() ) )
			{
				location	= &it->second;
				locationUri = it->first;
			}
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

std::string ServerConfig::indexFileName( Location const& location )
{
	std::string indexFileName( location.index );
	if ( indexFileName.empty() )
		indexFileName = "index.html";
	return indexFileName;
}

int short ServerConfig::statusLocationAccess( Location const& location, std::string const& fullPath )
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
		std::string index( location.index );
		if ( index.empty() )
			index = "index.html";
		if ( ServerConfig::statusLocationAccess( location, fullPath + '/' + index ) == 403 )
			return 403;
	}
	ifs.close();
	return 0;
}

bool ServerConfig::isDir( std::string const& path )
{
	struct stat pathStat;

	if ( stat( path.c_str(), &pathStat ) < 0 )
		return false;
	return S_ISDIR( pathStat.st_mode );
}
