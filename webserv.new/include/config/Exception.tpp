/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 20:19:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONFIG_EXCEPTION_TPP
#define WEBSERV_CONFIG_EXCEPTION_TPP

#include <exception>
#include <sstream>
#include "../config/Server.hpp"

namespace webserv
{

namespace config
{
class Exception : public std::exception
{
	public:
		Exception( void ) : msg_( "config: " ) {}
		Exception( Exception const& other ) : msg_( other.msg_ ) {}
		Exception& operator=( Exception const& other )
		{
			if ( this != &other )
				msg_ = other.msg_;
			return *this;
		}
		virtual ~Exception() throw() {}

		Exception( config::Server const& server, std::string const& locationPath )
		{
			std::ostringstream ss;
			std::string		   host( server.host );
			ss << "config: "
			   << "server=[" << host << "], port=[" << server.port << "]"
			   << ", location[" << locationPath << "]: ";
			msg_ = ss.str();
		}

		Exception( config::Server const& server )
		{
			std::ostringstream ss;
			std::string		   host( server.host );
			ss << "config: "
			   << "server=[" << host << "], port=[" << server.port << "]: ";
			msg_ = ss.str();
		}

		virtual char const* what() const throw() { return msg_.c_str(); }

		template < typename T >
		Exception& operator<<( T const& any )
		{
			std::ostringstream ss;
			ss << any;
			msg_ += ss.str();
			return *this;
		}

	private:
		std::string msg_;
};
}  // namespace config

}  // namespace webserv

#endif
