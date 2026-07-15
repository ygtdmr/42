/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/15 13:23:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Client.hpp"
#include "../../../inc/hpp/http/handler/Cgi.hpp"

void webserv::http::Client::process( void )
{
	short int revents(controller->getPollfd(fd).revents);
	if ( revents )
		lastActivity = std::time( 0 );
	if ( revents & POLLIN )
		receive();
	if ( revents & POLLOUT )
		deliver();
	try
	{
		if (handler)
		{
			handler::Cgi* cgiHandler( dynamic_cast<handler::Cgi*>(handler) );
			if ( cgiHandler || ( revents & POLLOUT ) )
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
	}
	
}
