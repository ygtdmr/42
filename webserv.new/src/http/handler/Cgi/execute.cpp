/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 10:36:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"

#include <fcntl.h>
#include <cstdlib>

bool webserv::http::handler::Cgi::execute( void )
{
	char const* scriptPath( realPath.substr( 0, realPath.find_last_of( "/" ) ).c_str() );
	char const* scriptFile( realPath.substr( realPath.find_last_of( "/" ) + 1 ).c_str() );
	char const* binPath( client->httpRequest.location->cgi.begin()->second.c_str() );
	int			pipeIn[2];
	int			pipeOut[2];

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

		chdir( scriptPath );

		char* args[3];
		args[0] = const_cast< char* >( binPath );
		args[1] = const_cast< char* >( scriptFile );
		args[2] = 0;

		execve( args[0], args, &env_[0] );
		std::exit( 1 );
	}
	else
	{
		close( pipeIn[0] );
		close( pipeOut[1] );

		struct pollfd pfd;
		pfd.revents = 0;

		if ( !client->httpRequest.body.empty() )
		{
			pfd.fd	   = pipeIn[1];
			pfd.events = POLLOUT;
			pollfds->push_back( pfd );
			connections->push_back( client );
			indexWrite = pollfds->size() - 1;
		}
		else
		{
			close( pipeIn[1] );
			indexWrite = -1;
		}

		pfd.fd	   = pipeOut[0];
		pfd.events = POLLIN;
		pollfds->push_back( pfd );
		connections->push_back( client );
		indexRead = pollfds->size() - 1;
	}
	return true;
}
