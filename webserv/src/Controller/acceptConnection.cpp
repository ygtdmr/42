/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/13 18:10:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctime>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/ServerLog.hpp"
#include "../../inc/hpp/manager/Client.hpp"

namespace webserv
{

void Controller::acceptConnection( size_t index ) const throw()
{
	if ( !( ( *pollfds )[index].revents & POLLIN ) )
		return;

	int server_fd = ( *pollfds )[index].fd;
	while ( true )
	{
		sockaddr_in addr;
		socklen_t	len( sizeof( addr ) );
		int			fd( accept( server_fd, ( sockaddr* )&addr, &len ) );

		if ( fd < 0 )
			break;
		if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		{
			close( fd );
			break;
		}

		manager::Client* client( new manager::Client() );
		client->server		 = dynamic_cast< manager::Server* >( ( *connections )[index] );
		client->addr		 = inet_ntoa( addr.sin_addr );
		client->lastActivity = std::time( 0 );
		client->controller	 = this;
		client->socketFd	 = fd;
		newConnection( fd, client );

		ServerLog( client->server, "WARNING" )
			<< "New connection from: " << client->addr << ", assigned socket: " << fd << '\n';
	}
}

}  // namespace webserv
