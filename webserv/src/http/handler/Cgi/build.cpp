/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 18:47:16 by yidemir          ###   ########.fr       */
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

#define RECV_BUFFER_SIZE 8

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
		int short const& revents( client->pollfd->revents );
		int const&		 fd( client->pollfd->fd );

		if ( ( indexWrite != -1 ) && ( fd == ( *client->controller->pollfds )[indexWrite].fd ) )
		{
			if ( revents & POLLOUT )
			{
				size_t	bytesLeft( client->httpRequest.body.size() - bodyBytesWritten_ );
				ssize_t bytesWritten( write( fd, client->httpRequest.body.c_str(), bytesLeft ) );

				if ( bytesWritten > 0 )
					bodyBytesWritten_ += bytesWritten;
				if ( bodyBytesWritten_ >= client->httpRequest.body.size() )
				{
					close( fd );
					( *client->posPoll )--;
					client->controller->pollfds->erase( client->controller->pollfds->begin() + indexWrite );
					client->controller->connections->erase( client->controller->connections->begin() +
															indexWrite );
					indexWrite = -1;
				}
			}
		}
		if ( ( fd == ( *client->controller->pollfds )[indexRead].fd ) )
		{
			if ( revents & POLLIN )
			{
				char	buffer[RECV_BUFFER_SIZE];
				ssize_t bytesRead( read( fd, buffer, sizeof( buffer ) - 1 ) );
				if ( bytesRead > 0 )
					body.append( buffer, bytesRead );
			}
			else if ( revents & POLLHUP )
			{
				int pidStatus;
				waitpid( pid_, &pidStatus, WNOHANG );
				close( fd );
				( *client->posPoll )--;
				client->controller->pollfds->erase( client->controller->pollfds->begin() + indexRead );
				client->controller->connections->erase( client->controller->connections->begin() +
														indexRead );

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
		client->pollfd = &( *client->controller->pollfds )[client->index];
	}
}
