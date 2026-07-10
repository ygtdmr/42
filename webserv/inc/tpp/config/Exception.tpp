/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:38:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONFIG_EXCEPTION_TPP
#define WEBSERV_CONFIG_EXCEPTION_TPP

#include "../../hpp/config/Exception.hpp"

namespace webserv
{

namespace config
{

Exception::Exception( void ) : msg_( "config: " ) {}
Exception::Exception( Exception const& other ) : msg_( other.msg_ ) {}
Exception& Exception::operator=( Exception const& other )
{
	if ( this != &other )
		msg_ = other.msg_;
	return *this;
}
Exception::~Exception() throw() {}

Exception::Exception( size_t serverIndex, std::string const& locationPath )
{
	std::ostringstream ss;
	ss << "config: "
	   << "server_index=[" << serverIndex << "], "
	   << "location[" << locationPath << "]: ";
	msg_ = ss.str();
}

Exception::Exception( size_t serverIndex )
{
	std::ostringstream ss;
	ss << "config: "
	   << "server=[" << serverIndex << "]: ";
	msg_ = ss.str();
}

char const* Exception::what() const throw()
{
	return msg_.c_str();
}

template < typename T >
Exception& Exception::operator<<( T const& any )
{
	std::ostringstream ss;
	ss << any;
	msg_ += ss.str();
	return *this;
}

}  // namespace config

}  // namespace webserv

#endif
