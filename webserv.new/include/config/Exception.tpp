/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 09:16:26 by yidemir          ###   ########.fr       */
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

		Exception( size_t serverIndex, std::string const& locationPath )
		{
			std::ostringstream ss;
			ss << "config: "
			   << "server_index=[" << serverIndex << "], "
			   << "location[" << locationPath << "]: ";
			msg_ = ss.str();
		}

		Exception( size_t serverIndex )
		{
			std::ostringstream ss;
			ss << "config: "
			   << "server=[" << serverIndex << "]: ";
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
