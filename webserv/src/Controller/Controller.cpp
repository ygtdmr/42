/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:18:28 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 22:49:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"

namespace webserv
{

Controller::Controller( void ) : pollfds(), servers(), clients() {}

Controller::Controller( Controller const& other )
{
	*this = other;
}

Controller::~Controller() {}

Controller& Controller::operator=( Controller const& other )
{
	if ( this != &other )
	{
		pollfds = other.pollfds;
		servers = other.servers;
		clients = other.clients;
	}
	return *this;
}

}  // namespace webserv
