/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptConnection.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 13:02:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctime>
#include "Controller.hpp"
#include "http/Log.hpp"
#include "http/Client.hpp"

std::string getAddr(uint32_t net_ip)
{
    unsigned char b1( net_ip & 0xFF );
    unsigned char b2( (net_ip >> 8) & 0xFF );
    unsigned char b3( (net_ip >> 16) & 0xFF );
    unsigned char b4( (net_ip >> 24) & 0xFF );

    std::stringstream ss;
    ss << static_cast<int>(b1) << "."
       << static_cast<int>(b2) << "."
       << static_cast<int>(b3) << "."
       << static_cast<int>(b4);
    
    return ss.str();
}

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
		client.addr		 = getAddr( addr.sin_addr.s_addr );
		client.lastActivity = std::time( 0 );
		newPollFd(fd);
		clients.push_back(client);

		http::Log( server, "WARNING" )
			<< "New connection from: " << client.addr << ", assigned socket: " << fd << '\n';
	}
}
