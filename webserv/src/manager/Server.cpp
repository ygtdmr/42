/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:52:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:10:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/manager/Server.hpp"

namespace webserv
{
namespace manager
{

Server::Server( void ) {}

Server::Server( Server const& other ) : Manager( other )
{
	*this = other;
}

Server::~Server() {}

Server& Server::operator=( Server const& other )
{
	if ( this != &other )
	{
		config = other.config;
		port   = other.port;
	}
	return *this;
}

}  // namespace manager

}  // namespace webserv
