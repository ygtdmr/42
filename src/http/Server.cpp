/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 11:52:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Server.hpp"

namespace webserv
{
namespace http
{

Server::Server( void ): fd(-1), addr(""), port(""), config(0) {}

Server::Server( Server const& other )
{
	*this = other;
}

Server::~Server() {}

Server& Server::operator=( Server const& other )
{
	if ( this != &other )
	{
		fd = other.fd;
		addr = other.addr;
		port   = other.port;
		config = other.config;
	}
	return *this;
}

}  // namespace manager

}  // namespace webserv
