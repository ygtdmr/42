/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.cpp                                        :+:      :+:    :+:   */
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
#include "parser/handler.hpp"

#define RECV_BUFFER_SIZE 65536

void webserv::http::Client::receive( void )
{
	char	buffer[RECV_BUFFER_SIZE];
	ssize_t bytesRead( recv( fd, buffer, sizeof( buffer ) - 1, 0 ) );
	if ( bytesRead > 0 )
	{
		Log( *server, "INFO" ) << "assigned socket: " << fd  << ", received bytes: " << bytesRead << '\n';
		receiveData.append( buffer, bytesRead );
		parserRequest.client = this;
		parserRequest.parse();
		receiveData.clear();
		receiveData = "";
		if ( !handler && ( parserRequest.currentState > parserRequest.HEADERS ) )
			parser::handler( *this );
		if ( parserRequest.currentState == parserRequest.DONE )
		{
			httpRequest.bodyEof = true;
			Log( *server, "INFO" )
				<< "assigned socket: " << fd << ", request received from: " << addr
				<< ", request_uri=[" << httpRequest.uri << "], method=[" << httpRequest.method << "]" << '\n';
			controller->getPollfd(fd).events = POLLOUT;
		}
	}
	else
		isConnectionClose = true;
}
