/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/28 11:54:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CONFIG_HPP
#define SERVER_CONFIG_HPP

#include <map>
#include <string>
#include <vector>

typedef struct LocationConfig
{
		bool						  autoindex;
		std::string					  index;
		std::string					  root;
		std::string					  uploadDir;
		std::string					  cgiExtension;
		std::string					  cgiPath;
		std::pair< int, std::string > redirect;
		std::vector< std::string >	  allowMethods;
} LocationConfig;

class ServerConfig
{
	public:
		ServerConfig( void );
		ServerConfig( ServerConfig const& other );
		~ServerConfig();

		ServerConfig&		  operator=( ServerConfig const& other );
		LocationConfig const* matchLocationConfig( std::string uri ) const;

		static std::string uriToPath( std::string const& uri );
		static int short   statusLocationAccess( LocationConfig const& locationConfig,
												 std::string const&	   fullPath );
		static bool		   isDir( std::string const& path );
		static std::string indexFileName( LocationConfig const& locationConfig );

		size_t									clientMaxBodySize;
		std::string								host;
		std::string								port;
		std::map< int, std::string >			errorPages;
		std::map< std::string, LocationConfig > locations;
};

#endif
