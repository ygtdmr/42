/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:47:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/03 12:31:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_CONFIG_HPP
#define WEBSERV_PARSER_CONFIG_HPP

#include <sstream>
#include "../config/Server.hpp"

namespace webserv
{
namespace parser
{

class Config
{
	public:
		Config( void );
		Config( Config const& other );
		~Config();
		Config&								 operator=( Config const& other );
		void								 parse( char const* path );
		void								 printServers( void ) const;
		std::vector< config::Server > const* getServers( void ) const;

	private:
		void putRaw( std::string const& line ) const;
		void putDataServer( config::Server& server );
		void putDataLocation( config::Location& location ) const;

		void parseStateGlobal( void );
		void parseStateServer( void );
		void parseStateLocation( config::Server& server, std::string const& path );

		void validateServer( void ) const;
		void validateLocation( std::string const& locationPath ) const;

		bool isValidDigit( std::string const& value ) const;
		bool isValidIPv4( std::string const& value ) const;
		bool isValidServerName( std::string const& value ) const;
		bool isValidMethod( std::string const& value ) const;
		bool isValidPath( std::string const& value, bool root = true ) const;

		std::stringstream*			   raw_;
		std::string					   key_;
		std::vector< std::string >	   values_;
		std::vector< config::Server >* servers_;
};

}  // namespace parser
}  // namespace webserv

#endif
