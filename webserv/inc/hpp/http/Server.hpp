/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/13 19:19:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_SERVER_HPP
#define WEBSERV_HTTP_SERVER_HPP

#include "../config/Server.hpp"

namespace webserv
{

namespace http
{
class Server
{
	public:
		Server( void );
		Server( Server const& other );
		~Server();
		Server& operator=( Server const& other );

		int					  fd;
		std::string			  addr;
		std::string			  port;
		config::Server const* config;
};
}  // namespace http

}  // namespace webserv

#endif
