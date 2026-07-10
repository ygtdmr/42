/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 13:59:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_MANAGER_SERVER_HPP
#define WEBSERV_MANAGER_SERVER_HPP

#include "../config/Server.hpp"
#include "Manager.hpp"

namespace webserv
{

namespace manager
{
class Server : public Manager
{
	public:
		Server( void );
		Server( Server const& other );
		~Server();
		Server& operator=( Server const& other );

		config::Server const* config;
		std::string			  port;
};
}  // namespace manager

}  // namespace webserv

#endif
