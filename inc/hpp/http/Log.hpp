/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/13 19:33:05 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_LOG_HPP
#define WEBSERV_HTTP_LOG_HPP

#include <string>
#include "Client.hpp"
#include "Server.hpp"

namespace webserv
{

namespace http
{

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

class Log
{
	public:
		inline Log( std::string const& level );
		inline Log( http::Server const& server, std::string const& level );
		inline Log( http::Client const& client, std::string const& level );
		template < typename T >
		inline Log& operator<<( T const& any );

	private:
		inline void printLog( void );

		std::string const& level_;
		std::string		   msg_;
};

}  // namespace http

}  // namespace webserv

#include "../../tpp/Log.tpp"

#endif
