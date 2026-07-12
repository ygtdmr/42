/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 11:43:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::process( void )
{
	if ( pollfd->revents )
		lastActivity = std::time( 0 );
	if ( !handler && ( pollfd->revents & POLLIN ) )
		receive();
	if ( handler )
	{
		if ( ( pollfd->fd != socketFd ) || ( pollfd->revents & POLLOUT ) )
		{
			try
			{
				handler->build();
			}
			catch ( http::handler::Handler* handler )
			{
				delete this->handler;
				this->handler = handler;
				handler->build();
			}
		}
		pollfd = &( *controller->pollfds )[*posPoll];
		if ( ( pollfd->fd == socketFd ) && ( pollfd->revents & POLLOUT ) )
			deliver();
	}
}
