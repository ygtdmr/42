/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 20:22:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <fcntl.h>
#include "../../hpp/Controller.hpp"
#include "../../hpp/ServerLog.hpp"
#include "../../hpp/manager/Client.hpp"

namespace webserv
{

void Controller::acceptConnection( size_t index ) const
{
	manager::Client client;
	sockaddr_in		addr;
	socklen_t		len( sizeof( addr ) );
	int				fd( accept( ( *pollfds_ )[index].fd, ( sockaddr* )&addr, &len ) );

	if ( fd < 0 )
		return;
	if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		return;

	client.addr = inet_ntoa( addr.sin_addr );
	connections_->push_back( client );
	pollfds_->push_back( client.pollfd );

	ServerLog( ( *connections_ )[index], "WARNING" )
		<< "New connection from: " << client.addr << ", assigned socket: " << fd << '\n';
}

}  // namespace webserv
