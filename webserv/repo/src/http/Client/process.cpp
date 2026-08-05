/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Client.hpp"
#include "http/handler/Cgi.hpp"

void webserv::http::Client::process( void )
{
	short int revents(controller->getPollfd(fd).revents);
	if ( revents )
		lastActivity = std::time( 0 );
	if ( revents & POLLIN )
		receive();
	try
	{
		if (handler)
		{
			if ( dynamic_cast<handler::Cgi*>(handler) || ( revents & POLLOUT ) )
			{
				handler->client = this;
				handler->build();
			}
		}
	}
	catch ( handler::Handler* handler_ )
	{
		if ( handler )
			delete handler;
		handler = handler_;
		deliverData.clear();
		deliverData = "";
		handler->build();
	}
	if ( revents & POLLOUT )
		deliver();
}
