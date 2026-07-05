/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deliver.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 09:36:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include "../../../inc/hpp/http/handler/Error.hpp"
#include "../../../inc/hpp/http/handler/Exception.hpp"
#include "../../../inc/hpp/manager/Client.hpp"
#include "../../../inc/hpp/parser/Handler.hpp"
#include "../../../inc/hpp/utils/map.hpp"

void webserv::manager::Client::deliver( void )
{
	try
	{
		handler->build();
	}
	catch ( http::handler::Exception const& e )
	{
		deliverData		= std::string();
		handler			= new http::handler::Error( e.status );
		handler->client = this;
		handler->build();
	}
	send( pollfd.fd, deliverData.c_str(), deliverData.length(), 0 );
	if ( handler->currentState == handler->DONE )
	{
		isConnectionClose =
			!utils::map::isEq< std::string, std::string >( handler->headers, "Connection", "keep-alive" );
		clear();
		if ( !isConnectionClose )
			pollfd.events = POLLIN;
	}
}
