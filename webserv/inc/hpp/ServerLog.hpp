/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerLog.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/13 17:40:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_SERVER_LOG_HPP
#define WEBSERV_SERVER_LOG_HPP

#include <string>
#include "manager/Server.hpp"

namespace webserv
{

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

class ServerLog
{
	public:
		inline ServerLog( std::string const& level );
		inline ServerLog( manager::Manager const* manager, std::string const& level );
		template < typename T >
		inline ServerLog& operator<<( T const& any );

	private:
		inline void printLog( void );

		std::string const& level_;
		std::string		   msg_;
};

}  // namespace webserv

#include "../tpp/ServerLog.tpp"

#endif
