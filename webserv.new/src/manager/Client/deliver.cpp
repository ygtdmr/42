/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deliver.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 11:25:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/http/handler/Handler.hpp"
#include "../../../inc/hpp/utils/map.hpp"

void webserv::manager::Client::deliver( void )
{
	try
	{
		handler->build();
	}
	catch ( http::handler::Handler* handler )
	{
		delete this->handler;
		this->handler	= handler;
		handler->client = this;
		handler->build();
	}
	send( pollfd.fd, deliverData.c_str(), deliverData.length(), 0 );
	deliverData = std::string();
	if ( handler->currentState == handler->DONE )
	{
		isConnectionClose =
			!utils::map::isEq< std::string, std::string >( handler->headers, "Connection", "keep-alive" );
		clear();
		if ( !isConnectionClose )
			pollfd.events = POLLIN;
	}
}
