/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:01:24 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/15 13:36:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/wait.h>
#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/Client.hpp"
#include "../../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"

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
				body.append( buffer, bytesRead );
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

			if ( pidStatus != 0 )
				throw new Error( client, 500 );

			std::map< std::string, std::string > cgiHeaders( parser::headersToMap( body, false ) );
			headers.insert( cgiHeaders.begin(), cgiHeaders.end() );
			if ( headers.find( "Status" ) == headers.end() )
				status = 200;
			else
				status = utils::conv::strTo< int short >( headers["Status"] );
			headers["Content-Length"] = utils::conv::toStr< size_t >( body.size() );
			client->deliverData		  = getFirstLine() + parser::mapToHeaders( headers ) + body;
			currentState			  = DONE;
		}
	}
}
