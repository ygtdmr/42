/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:52:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONFIG_EXCEPTION_HPP
#define WEBSERV_CONFIG_EXCEPTION_HPP

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
		inline Exception( void );
		inline Exception( Exception const& other );
		inline Exception& operator=( Exception const& other );
		inline virtual ~Exception() throw();

		inline Exception( size_t serverIndex, std::string const& locationPath );
		inline Exception( size_t serverIndex );

		inline virtual char const* what() const throw();

		template < typename T >
		inline Exception& operator<<( T const& any );
	private:
		std::string msg_;
};
}  // namespace config

}  // namespace webserv

#include "../../tpp/config/Exception.tpp"

#endif
