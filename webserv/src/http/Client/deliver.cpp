/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deliver.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 17:44:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/http/Log.hpp"
#include "../../../inc/hpp/http/Client.hpp"

void webserv::http::Client::deliver( void )
{
	if ( !deliverData.empty() )
	{
		ssize_t bytesSent( send( fd, deliverData.c_str() + deliverOffset, deliverData.length() - deliverOffset, 0 ) );
		if ( bytesSent > 0 )
		{
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
		http::Log( *server, "INFO" ) << "Response sent to: " << addr << ", assigned socket: " << fd
									<< ", uri=[" << httpRequest.uri << "], status=[" << handler->status << "]"
									<< '\n';
		isConnectionClose = ( handler->headers["Connection"] == "close" );
		clear();
		if ( !isConnectionClose )
			controller->getPollfd(fd).events = POLLIN;
	}
}
