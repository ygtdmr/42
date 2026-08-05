/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Client.hpp"
#include "http/handler/Cgi.hpp"
#include "http/handler/Error.hpp"

void webserv::http::handler::Cgi::build( void )
{
	if ( pid_ == -1 )
	{
		if ( client->controller->getPollfd(client->fd).revents & POLLOUT )
		{
			setupEnv();
			if ( !execute() )
				throw new Error( client, 500 );
		}
	}
	else
		process();
}
