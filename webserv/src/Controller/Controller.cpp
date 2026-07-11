/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:18:28 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 10:52:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"
#include <unistd.h>

namespace webserv
{

Controller::Controller( void )
{
	connections = new std::vector< manager::Manager* >;
	pollfds		= new std::vector< struct pollfd >;
}

Controller::Controller( Controller const& other )
{
	*this = other;
}

Controller::~Controller()
{
	for ( size_t i = 0; i < pollfds->size(); i++ )
		close( ( pollfds->begin() + i )->fd );
	for ( size_t i = 0; i < connections->size(); i++ )
		delete ( *connections )[i];
	delete connections;
	delete pollfds;
}

Controller& Controller::operator=( Controller const& other )
{
	if ( this != &other )
	{
		*connections = *other.connections;
		*pollfds	 = *other.pollfds;
	}
	return *this;
}

}  // namespace webserv
