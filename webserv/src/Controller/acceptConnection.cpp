/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 15:36:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctime>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/http/Log.hpp"
#include "../../inc/hpp/http/Client.hpp"

void webserv::Controller::acceptConnection( http::Server const& server ) throw()
{
	if ( !( getPollfd(server.fd).revents & POLLIN ) )
		return;

	while ( true )
	{
		sockaddr_in addr;
		socklen_t	len( sizeof( addr ) );
		int			fd( accept( server.fd, ( sockaddr* )&addr, &len ) );

		if ( fd < 0 )
			break;
		if ( fcntl( fd, F_SETFL, O_NONBLOCK ) < 0 )
		{
			close( fd );
			break;
		}

		http::Client client;
		client.fd	 = fd;
		client.server	 = &server;
		client.controller	 = this;
		client.addr		 = inet_ntoa( addr.sin_addr );
		client.lastActivity = std::time( 0 );
		newPollFd(fd);
		clients.push_back(client);

		http::Log( server, "WARNING" )
			<< "New connection from: " << client.addr << ", assigned socket: " << fd << '\n';
	}
}
