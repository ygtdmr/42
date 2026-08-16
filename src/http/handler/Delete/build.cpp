/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:54:55 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:54:57 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sys/stat.h>
#include <cstdio>
#include "http/handler/Delete.hpp"
#include "http/handler/Error.hpp"
#include "http/Client.hpp"

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
