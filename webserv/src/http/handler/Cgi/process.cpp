/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:01:24 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/19 12:20:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/wait.h>
#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/Client.hpp"
#include "../../../../inc/hpp/http/Headers.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"
#include "../../../../inc/hpp/utils/str.hpp"

#define RECV_BUFFER_SIZE 65536

void webserv::http::handler::Cgi::process( void )
{
	if ( pipeInFd != -1 )
	{
		int short revents(client->controller->getPollfd(pipeInFd).revents);
		if ( revents & POLLOUT )
		{
			ssize_t bytesWritten( write( pipeInFd,
										client->httpRequest.body.c_str() + bodySent,
										client->httpRequest.body.size() - bodySent ) );
			if ( bytesWritten > 0 )
				bodySent += bytesWritten;
			if ( bodySent == client->httpRequest.body.size() )
			{
				if ( client->httpRequest.bodyEof )
				{
					client->controller->removePollfd(pipeInFd);
					close(pipeInFd);
					pipeInFd = -1;
				}
				else
					client->controller->getPollfd(client->fd).events = POLLIN;
			}
		}
	}
	if ( pipeOutFd != -1 )
	{
		int short revents(client->controller->getPollfd(pipeOutFd).revents);
		bool eof( false );
		if ( revents & POLLIN )
		{
			char	buffer[RECV_BUFFER_SIZE];
			ssize_t bytesRead( read( pipeOutFd, buffer, sizeof( buffer ) - 1 ) );
			if ( bytesRead > 0 )
			{
				if ( currentState == HEADERS )
				{
					body.append( buffer, bytesRead );
					if ( utils::str::has(body, "\r\n\r\n") || utils::str::has(body, "\n\n") )
					{
						headers.merge( Headers(body, false) );
						if ( (!headers.has( "Content-Length" ) ) || !headers.match("Transfer-Encoding", "chunked") )
							headers.set("Connection", "close");
						if ( !headers.has( "Status" ) )
							status = 200;
						else
							status = utils::conv::strTo< int short >( headers.get("Status") );
						client->deliverData =  getFirstLine() + headers.str() + body;
						currentState = BODY;
					}
				}
				else if ( currentState == BODY )
					client->deliverData.append( buffer, bytesRead );
			}
			else
				eof = true;
		}
		if ( eof || ( revents & POLLHUP ) )
		{
			client->controller->removePollfd(pipeOutFd);
			close(pipeOutFd);
			pipeOutFd = -1;

			int pidStatus( 0 );
			kill( pid_, SIGKILL );
			waitpid( pid_, &pidStatus, WNOHANG );

			if ( (pidStatus != 0) || (status == 0) )
				throw new Error( client, 500 );

			currentState = DONE;
		}
	}
}
