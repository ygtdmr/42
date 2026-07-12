/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 19:52:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"

#define RECV_BUFFER_SIZE 65536

void webserv::http::handler::Cgi::build( void )
{
	if ( pid_ == -1 )
	{
		setupEnv();
		if ( !execute() )
			throw new Error( client, 500 );
	}
	else
	{
		int short const revents( client->pollfd->revents );
		int const		fd( client->pollfd->fd );

		if ( ( pipeInFd != -1 ) && ( fd == pipeInFd ) )
		{
			if ( revents & POLLOUT )
			{
				ssize_t bytesWritten( write( fd,
											 client->httpRequest.body.c_str() + bodySent,
											 client->httpRequest.body.size() - bodySent ) );
				if ( bytesWritten > 0 )
					bodySent += bytesWritten;
				else
					bodySent = client->httpRequest.body.size();
				if ( bodySent >= client->httpRequest.body.size() )
				{
					client->controller->removeFd( pipeInFd, client->posPoll );
					pipeInFd = -1;
				}
			}
		}
		if ( ( pipeOutFd != -1 ) && ( fd == pipeOutFd ) )
		{
			bool eof( false );
			if ( revents & POLLIN )
			{
				char	buffer[RECV_BUFFER_SIZE];
				ssize_t bytesRead( read( fd, buffer, sizeof( buffer ) - 1 ) );
				if ( bytesRead > 0 )
					body.append( buffer, bytesRead );
				else
					eof = true;
			}
			if ( eof || ( revents & POLLHUP ) )
			{
				int pidStatus;
				if ( waitpid( pid_, &pidStatus, WNOHANG ) == 0 )
				{
					kill( pid_, SIGKILL );
					waitpid( pid_, &pidStatus, 0 );
				}
				client->controller->removeFd( pipeOutFd, client->posPoll );
				pipeOutFd = -1;

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
}
