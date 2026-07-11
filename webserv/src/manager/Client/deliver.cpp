/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deliver.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 11:41:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/ServerLog.hpp"
#include "../../../inc/hpp/http/handler/Handler.hpp"
#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::deliver( void )
{
	if ( !deliverData.empty() )
	{
		ssize_t bytesSent( send( pollfd->fd, deliverData.c_str(), deliverData.length(), 0 ) );
		if ( bytesSent > 0 )
			deliverData.erase( 0, bytesSent );
	}
	if ( ( handler->currentState == handler->DONE ) && deliverData.empty() )
	{
		ServerLog( server, "INFO" )
			<< "Response sent to: " << addr << ", assigned socket: " << pollfd->fd << ", uri=["
			<< httpRequest.uri << "], status=[" << handler->status << "]" << '\n';
		isConnectionClose = ( handler->headers["Connection"] == "close" );
		clear();
		if ( !isConnectionClose )
			pollfd->events = POLLIN;
	}
}
