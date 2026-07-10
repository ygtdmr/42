/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deliver.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 17:24:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/ServerLog.hpp"
#include "../../../inc/hpp/http/handler/Handler.hpp"
#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::deliver( void )
{
	try
	{
		handler->build();
	}
	catch ( http::handler::Handler* handler )
	{
		delete this->handler;
		this->handler = handler;
		handler->build();
	}
	send( pollfd->fd, deliverData.c_str(), deliverData.length(), 0 );
	deliverData = std::string();
	if ( handler->currentState == handler->DONE )
	{
		ServerLog( server, "INFO" ) << "Response sent to: " << addr << ", assigned socket: " << pollfd->fd
									<< ", uri=[" << httpRequest.uri << "], status=[" << handler->status << "]"
									<< '\n';
		isConnectionClose = ( handler->headers["Connection"] == "close" );
		clear();
		if ( !isConnectionClose )
			pollfd->events = POLLIN;
	}
}
