/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 23:10:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/http/Log.hpp"
#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/parser/handler.hpp"

#define RECV_BUFFER_SIZE 65536

void webserv::http::Client::receive( void )
{
	char	buffer[RECV_BUFFER_SIZE];
	ssize_t bytesRead( recv( fd, buffer, sizeof( buffer ) - 1, 0 ) );
	if ( bytesRead > 0 )
	{
		receiveData.append( buffer, bytesRead );
		parserRequest.parse();
		receiveData.clear();
		receiveData = "";
		Log( *server, "INFO" ) << "received bytes: " << bytesRead << ", assigned socket: " << fd
									<< '\n';
		if ( !handler && ( parserRequest.currentState > parserRequest.HEADERS ) )
			parser::handler( *this );
		if ( parserRequest.currentState == parserRequest.DONE )
		{
			httpRequest.bodyEof = true;
			Log( *server, "INFO" )
				<< "Request received from: " << addr << ", assigned socket: " << fd
				<< ", request_uri=[" << httpRequest.uri << "], method=[" << httpRequest.method << "]" << '\n';
			controller->getPollfd(fd).events = POLLOUT;
		}
	}
	else
		isConnectionClose = true;
}
