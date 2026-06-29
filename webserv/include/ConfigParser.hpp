/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:52:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 10:32:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_PARSER_HPP
#define CONFIG_PARSER_HPP

#include "ServerConfig.hpp"

class ConfigParser
{
	public:
		ConfigParser( std::string const& path );
		ConfigParser( ConfigParser const& other );
		~ConfigParser();
		ConfigParser&					   operator=( ConfigParser const& other );
		std::vector< ServerConfig > const* getServers( void ) const;
		void							   parse( void );

	private:
		void putRaw( std::string const& line ) const;

		void parseStateGlobal( void );
		void parseStateServer( void );
		void parseStateLocation( ServerConfig& serverConfig, std::string const& path );

		void validateServerConfig( ServerConfig const& serverConfig );
		void validateLocation( ServerConfig const& serverConfig, std::string const& locationPath );

		void putDataServerConfig( ServerConfig& serverConfig );
		void putDataLocation( Location& location );

		bool isValidDigit( std::string const& value );
		bool isValidIPv4( std::string const& value );
		bool isValidPath( std::string const& value, bool root = true );

		std::string					 path_;
		std::string					 key_;
		std::vector< std::string >	 values_;
		std::stringstream*			 raw_;
		std::vector< ServerConfig >* servers_;
};

#endif
