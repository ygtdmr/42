/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigException.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 18:13:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_EXCEPTION_TPP
#define CONFIG_EXCEPTION_TPP

#include <exception>
#include <sstream>
#include "ServerConfig.hpp"

class ConfigException : public std::exception
{
	public:
		ConfigException( void ) : msg_( "config: " ) {}

		ConfigException( ServerConfig const& serverConfig, std::string const& locationPath )
		{
			std::ostringstream ss;
			std::string		   host( serverConfig.host );
			if ( host.empty() )
				host = "::";
			ss << "config: "
			   << "server=[" << host << "], port=[" << serverConfig.port << "]"
			   << ", location[" << locationPath << "]: ";
			msg_ = ss.str();
		}

		ConfigException( ServerConfig const& serverConfig )
		{
			std::ostringstream ss;
			std::string		   host( serverConfig.host );
			if ( host.empty() )
				host = "::";
			ss << "config: "
			   << "server=[" << host << "], port=[" << serverConfig.port << "]: ";
			msg_ = ss.str();
		}

		virtual ~ConfigException() throw() {}

		virtual char const* what() const throw() { return msg_.c_str(); }

		template < typename T >
		ConfigException& operator<<( T const& any )
		{
			std::ostringstream ss;
			ss << any;
			msg_ += ss.str();
			return *this;
		}

	private:
		std::string msg_;
};

#endif
