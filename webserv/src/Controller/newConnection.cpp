/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newConnection.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 08:57:18 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 17:59:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"

void webserv::Controller::newConnection( int fd, manager::Manager* connection ) const
{
	struct pollfd pfd;
	pfd.events	= POLLIN;
	pfd.revents = 0;
	pfd.fd		= fd;

	pollfds->push_back( pfd );
	connections->push_back( connection );

	for ( size_t i = 0; i < connections->size(); ++i )
		( *connections )[i]->pollfd = &( *pollfds )[i];
}
