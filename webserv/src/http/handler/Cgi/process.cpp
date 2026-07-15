/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:01:24 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 23:03:02 by yidemir          ###   ########.fr       */
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

static void removeCgiFd( int fd, std::vector<int>& cgiFds )
{
	std::vector<int>::iterator it(cgiFds.begin());
	while (it != cgiFds.end())
	{
		if ( *it == fd)
		{
			cgiFds.erase(it);
			break;
		}
		it++;
	}
}

void webserv::http::handler::Cgi::process( void )
{
	for (size_t i = 0; i < client->cgiFds.size(); i++)
	{
		int const		fd( client->cgiFds[i] );
		int short revents(client->controller->getPollfd(fd).revents);

		if ( fd == pipeInFd )
		{
			if ( revents & POLLOUT )
			{
				ssize_t bytesWritten( write( fd,
											client->httpRequest.body.c_str() + bodySent,
											client->httpRequest.body.size() - bodySent ) );
				if ( bytesWritten > 0 )
					bodySent += bytesWritten;
				if ( bodySent == client->httpRequest.body.size() )
				{
					if ( client->httpRequest.bodyEof )
					{
						client->controller->removePollfd(pipeInFd);
						removeCgiFd(pipeInFd, client->cgiFds);
						close(pipeInFd);
						pipeInFd = -1;
					}
					else
					{
						client->httpRequest.body.clear();
						client->httpRequest.body = "";
						bodySent = 0;
						client->controller->getPollfd(client->fd).events = POLLIN;
					}
				}
			}
		}
		if ( fd == pipeOutFd )
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
				client->controller->removePollfd(pipeOutFd);
				removeCgiFd(pipeOutFd, client->cgiFds);
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
}
