/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:54:57 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/15 18:57:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerConfig.hpp"

struct ConfigParserToken
{
	std::vector<std::string>	words;
	ConfigParserToken			*child;
};

class ConfigParser
{
	public:
		ConfigParser( std::string const& path );
		ConfigParser( ConfigParser const& other );
		~ConfigParser();
		ConfigParser				&operator=( ConfigParser const& other );
		std::vector<ServerConfig>	*getServers( void ) const;
		void						parse( void );
	private:
		void						throwError( std::string const& msg ) const;
		ConfigParserToken			*getToken( std::ifstream& ifs ) const;

		std::string					path_;
		std::vector<ServerConfig>	*servers_;
};
