/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 22:36:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/Client.hpp"

#include <fcntl.h>
#include <cstdlib>

bool webserv::http::handler::Cgi::execute( void )
{
	std::string const scriptPath = realPath.substr( 0, realPath.find_last_of( "/" ) );
	std::string const scriptFile = realPath.substr( realPath.find_last_of( "/" ) + 1 );
	std::string const binPath( client->httpRequest.location->cgi.begin()->second );
	int				  pipeIn[2];
	int				  pipeOut[2];

	if ( pipe( pipeIn ) < 0 || pipe( pipeOut ) < 0 )
		return false;

	fcntl( pipeIn[1], F_SETFL, O_NONBLOCK );
	fcntl( pipeOut[0], F_SETFL, O_NONBLOCK );

	pid_ = fork();

	if ( pid_ < 0 )
		return false;

	if ( pid_ == 0 )
	{
		dup2( pipeIn[0], 0 );
		dup2( pipeOut[1], 1 );

		close( pipeIn[1] );
		close( pipeOut[0] );
		close( pipeIn[0] );
		close( pipeOut[1] );

		if ( chdir( scriptPath.c_str() ) < 0 )
			std::exit( 1 );

		char* args[3];
		args[0] = const_cast< char* >( binPath.c_str() );
		args[1] = const_cast< char* >( scriptFile.c_str() );
		args[2] = 0;

		execve( args[0], args, &env_[0] );
		std::exit( 1 );
	}
	else
	{
		close( pipeIn[0] );
		close( pipeOut[1] );

		if ( !client->httpRequest.body.empty() )
		{
			pipeInFd = pipeIn[1];
			client->controller->newPollFd(pipeInFd, POLLOUT);
			client->cgiFds.push_back(pipeInFd);
		}
		else
		{
			close( pipeIn[1] );
			pipeInFd = -1;
		}
		pipeOutFd = pipeOut[0];
		client->controller->newPollFd(pipeOutFd, POLLIN);
		client->cgiFds.push_back(pipeOutFd);
	}
	return true;
}
