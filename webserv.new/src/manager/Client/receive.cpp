/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 09:29:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/parser/Handler.hpp"

#define RECV_BUFFER_SIZE 8

void webserv::manager::Client::receive( void )
{
	char	buffer[RECV_BUFFER_SIZE];
	ssize_t bytesRead( recv( pollfd.fd, buffer, sizeof( buffer ) - 1, 0 ) );
	if ( bytesRead > 0 )
	{
		receiveData.append( buffer, bytesRead );
		parserRequest.parse();
		if ( parserRequest.currentState == parserRequest.DONE )
		{
			parser::Handler parserHandler;
			parserHandler.parse( this );
			handler		  = parserHandler.getHandler();
			pollfd.events = POLLOUT;
		}
	}
	else
		isConnectionClose = true;
}
