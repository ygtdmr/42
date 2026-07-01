/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:47:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:51:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_CONFIG_HPP
#define PARSER_CONFIG_HPP

#include "ServerConfig.hpp"

namespace parser {

class Config
{
	public:
		Config( std::string const& path );
		Config( Config const& other );
		~Config();
		Config&					   operator=( Config const& other );
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

		bool isValidDigit( std::string const& value ) const;
		bool isValidIPv4( std::string const& value ) const;
		bool isValidPath( std::string const& value, bool root = true ) const;

		std::string					 path_;
		std::string					 key_;
		std::vector< std::string >	 values_;
		std::stringstream*			 raw_;
		std::vector< ServerConfig >* servers_;
};

}

#endif
