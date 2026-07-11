/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 18:47:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/ServerLog.hpp"
#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/parser/handler.hpp"

#define RECV_BUFFER_SIZE 65536

void webserv::manager::Client::receive( void )
{
	char	buffer[RECV_BUFFER_SIZE];
	ssize_t bytesRead( recv( pollfd->fd, buffer, sizeof( buffer ) - 1, 0 ) );
	if ( bytesRead > 0 )
	{
		receiveData.append( buffer, bytesRead );
		parserRequest.parse();
		if ( parserRequest.currentState == parserRequest.DONE )
		{
			ServerLog( server, "INFO" )
				<< "Request received from: " << addr << ", assigned socket: " << pollfd->fd
				<< ", request_uri=[" << httpRequest.uri << "], method=[" << httpRequest.method << "]" << '\n';
			parser::handler( this );
			pollfd->events = POLLOUT;
		}
	}
	else
		isConnectionClose = true;
}
