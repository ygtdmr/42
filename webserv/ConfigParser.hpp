/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:54:57 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/14 21:04:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include "ServerConfig.hpp"

class ConfigParser
{
	public:
		ConfigParser( std::string const& path );
		ConfigParser( ConfigParser const& other );
		~ConfigParser();
		ConfigParser	&operator=( ConfigParser const& other );
		ServerConfig	*getServerConfig( void );
		void			parse( void );
	private:
		std::string		path_;
		ServerConfig	*serverConfig_;
};
