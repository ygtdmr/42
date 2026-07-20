/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deliver.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "http/Log.hpp"
#include "http/Client.hpp"

void webserv::http::Client::deliver( void )
{
	if ( !deliverData.empty() )
	{
		ssize_t bytesSent( send( fd, deliverData.c_str() + deliverOffset, deliverData.length() - deliverOffset, 0 ) );
		if ( bytesSent > 0 )
		{
			Log( *server, "INFO" ) << "assigned socket: " << fd <<  ", sent bytes: " << bytesSent << '\n';
			deliverOffset += bytesSent;
			if ( deliverOffset >= deliverData.length() )
			{
				deliverData.clear();
				deliverData = "";
				deliverOffset = 0;
			}
		}
		else
		{
			isConnectionClose = true;
			return;
		}
	}
	if ( ( handler->currentState == handler->DONE ) && deliverData.empty() )
	{
		Log( *server, "INFO" )  << "assigned socket: " << fd << ", response sent to: " << addr
									<< ", uri=[" << httpRequest.uri << "], status=[" << handler->status << "]"
									<< '\n';
		isConnectionClose = handler->headers.match("Connection", "close");
		clear();
		if ( !isConnectionClose )
			controller->getPollfd(fd).events = POLLIN;
	}
}
