/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 10:34:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"

#define RECV_BUFFER_SIZE 8

void webserv::http::handler::Cgi::build( void )
{
	if ( !isExec_ )
	{
		setupEnv();
		if ( !execute() )
			throw new Error( client, 500 );
		isExec_ = true;
	}
	else
	{
		int short const& revents( client->pollfd->revents );
		int const&		 fd( client->pollfd->fd );

		if ( ( indexWrite != -1 ) && ( fd == ( *pollfds )[indexWrite].fd ) )
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
					( *posPollds )--;
					pollfds->erase( pollfds->begin() + indexWrite );
					connections->erase( connections->begin() + indexWrite );
					indexWrite = -1;
				}
			}
		}
		if ( ( fd == ( *pollfds )[indexRead].fd ) )
		{
			if ( revents & POLLIN )
			{
				char	buffer[RECV_BUFFER_SIZE];
				ssize_t bytesRead( read( fd, buffer, sizeof( buffer ) - 1 ) );
				if ( bytesRead > 0 )
					client->deliverData.append( buffer, bytesRead );
			}
			else if ( revents & POLLHUP )
			{
				int status;
				waitpid( pid_, &status, WNOHANG );
				close( fd );
				( *posPollds )--;
				pollfds->erase( pollfds->begin() + indexRead );
				connections->erase( connections->begin() + indexRead );
				status		 = 200;
				currentState = DONE;
			}
		}
		client->pollfd = &( *pollfds )[indexClient];
	}
}
