/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:55:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_CONFIG_HPP
#define SERVER_CONFIG_HPP

#include <map>
#include <string>
#include <vector>

typedef struct
{
		size_t							  	clientMaxBodySize;
		bool								autoindex;
		std::string							index;
		std::string							root;
		std::string							uploadDir;
		std::string							cgiExtension;
		std::string							cgiPath;
		std::pair< int short, std::string > redirect;
		std::vector< std::string >			allowMethods;
} Location;

class ServerConfig
{
	public:
		ServerConfig( void );
		ServerConfig( ServerConfig const& other );
		~ServerConfig();

		ServerConfig&	operator=( ServerConfig const& other );
		Location const* matchLocation( std::string uri ) const;

		size_t							  clientMaxBodySize;
		std::string						  root;
		std::string						  serverName;
		std::string						  host;
		std::string						  port;
		std::map< int short, std::string >	  errorPages;
		std::map< std::string, Location > locations;
};

std::ostream	&operator<<( std::ostream &os, ServerConfig const &serverConfig );

#endif
