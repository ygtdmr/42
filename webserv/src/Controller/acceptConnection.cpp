/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 18:22:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <fcntl.h>
#include <ctime>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/ServerLog.hpp"
#include "../../inc/hpp/manager/Client.hpp"

namespace webserv
{

void Controller::acceptConnection( size_t index ) const throw()
{
	sockaddr_in addr;
	socklen_t	len( sizeof( addr ) );
	int			fd( accept( ( *pollfds )[index].fd, ( sockaddr* )&addr, &len ) );

	if ( fd < 0 )
		return;
	if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		return;

	manager::Client* client( new manager::Client() );
	client->server		 = dynamic_cast< manager::Server* >( ( *connections )[index] );
	client->addr		 = inet_ntoa( addr.sin_addr );
	client->lastActivity = std::time( 0 );
	client->controller	 = this;
	newConnection( fd, client );
	client->index = client->controller->pollfds->size() - 1;

	ServerLog( client, "WARNING" ) << "New connection from: " << client->addr << ", assigned socket: " << fd
								   << '\n';
}

}  // namespace webserv
