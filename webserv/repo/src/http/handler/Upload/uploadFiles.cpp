/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uploadFiles.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/handler/Error.hpp"
#include "http/handler/Upload.hpp"
#include "http/Client.hpp"
#include "utils/str.hpp"

void webserv::http::handler::Upload::uploadFiles( void )
{
	if ( client->httpRequest.location->uploadDir.empty() )
		throw new Error( client, 500 );
	std::string contentType(client->httpRequest.headers.get("Content-Type"));
	if ( utils::str::has( contentType, "boundary=" ) )
		writeBoundary( utils::str::crop( contentType, "boundary=" ) );
	else
		writeRaw( contentType );
}
