/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newConnection.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 08:57:18 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 16:44:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"

void webserv::Controller::newConnection( int fd, manager::Manager* connection ) const
{
	struct pollfd pfd;
	pfd.events	= POLLIN;
	pfd.revents = 0;
	pfd.fd		= fd;

	pollfds_->push_back( pfd );

	connection->pollfd = &( *( pollfds_->end() - 1 ) );
	connections_->push_back( connection );
}
