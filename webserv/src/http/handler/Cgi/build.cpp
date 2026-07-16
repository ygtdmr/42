/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/16 18:44:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/Client.hpp"
#include "../../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"

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
