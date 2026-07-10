/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 10:41:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::process( void )
{
	if ( pollfd->revents )
		lastActivity = std::time( 0 );
	if ( dynamic_cast< http::handler::Cgi* >( handler ) )
		deliver();
	else
	{
		if ( pollfd->revents & POLLIN )
			receive();
		if ( pollfd->revents & POLLOUT )
			deliver();
	}
}
