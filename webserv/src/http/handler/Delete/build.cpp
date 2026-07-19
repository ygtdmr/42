/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 19:39:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <cstdio>
#include "../../../../inc/hpp/http/handler/Delete.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/Client.hpp"

void webserv::http::handler::Delete::build( void )
{
	struct stat fileStat;

	if ( stat( realPath.c_str(), &fileStat ) < 0 )
		throw new Error( client, 404 );

	if ( S_ISDIR( fileStat.st_mode ) )
		throw new Error( client, 403 );

	if ( std::remove( realPath.c_str() ) < 0 )
		throw new Error( client, 500 );

	status				= 204;
	client->deliverData = getFirstLine() + headers.str();
	currentState		= DONE;
}
