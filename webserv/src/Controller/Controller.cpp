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
	std::vector< manager::Manager* > uniqueManagers;

	for ( size_t i = 0; i < connections->size(); i++ )
	{
		manager::Manager* m(( *connections )[i]);
		bool			  found(false);
		for ( size_t j = 0; j < uniqueManagers.size(); ++j )
		{
			if ( uniqueManagers[j] == m )
			{
				found = true;
				break;
			}
		}
		if ( !found )
			uniqueManagers.push_back( m );
	}
	for ( size_t i = 0; i < pollfds->size(); i++ )
		close( ( *pollfds )[i].fd );

	pollfds->clear();
	connections->clear();

	for ( size_t i = 0; i < uniqueManagers.size(); i++ )
		delete uniqueManagers[i];

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
