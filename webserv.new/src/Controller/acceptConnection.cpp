/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 14:25:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <fcntl.h>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/ServerLog.hpp"
#include "../../inc/hpp/manager/Client.hpp"

namespace webserv
{

void Controller::acceptConnection( size_t index ) const throw()
{
	sockaddr_in addr;
	socklen_t	len( sizeof( addr ) );
	int			fd( accept( ( *pollfds_ )[index].fd, ( sockaddr* )&addr, &len ) );

	if ( fd < 0 )
		return;
	if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		return;

	manager::Client* client( new manager::Client() );
	client->server = dynamic_cast< manager::Server* >( ( *connections_ )[index] );
	client->addr   = inet_ntoa( addr.sin_addr );
	newConnection( fd, client );

	ServerLog( client, "WARNING" ) << "New connection from: " << client->addr << ", assigned socket: " << fd
								   << '\n';
}

}  // namespace webserv
