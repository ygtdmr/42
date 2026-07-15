/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 17:05:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Client.hpp"

void webserv::http::Client::process( void )
{
	short int revents(controller->getPollfd(fd).revents);
	if ( revents )
		lastActivity = std::time( 0 );
	if ( revents & POLLIN )
		receive();
	if ( revents & POLLOUT )
	{
		try
		{
			if (handler)
				handler->build();
		}
		catch ( handler::Handler* handler_ )
		{
			if ( handler )
				delete handler;
			handler = handler_;
			handler->build();
		}
		deliver();
	}
}
