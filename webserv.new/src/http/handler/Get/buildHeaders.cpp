/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:47:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include "../../../../inc/hpp/http/handler/DirectoryListing.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/handler/Get.hpp"
#include "../../../../inc/hpp/http/handler/Redirection.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/extToMimeType.hpp"
#include "../../../../inc/hpp/parser/fileExt.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"

void webserv::http::handler::Get::buildHeaders( void )
{
	struct stat st;
	if ( stat( realPath.c_str(), &st ) < 0 )
		throw new Error( client, 404 );
	if ( S_ISDIR( st.st_mode ) )
	{
		if ( *( client->httpRequest.uriPath.end() - 1 ) != '/' )
			throw new Redirection( client, 301, client->httpRequest.uriPath + '/' );
		std::string indexFile( client->httpRequest.location->index );
		if ( indexFile.empty() )
			indexFile = "index.html";
		realPath += "/" + indexFile;
		if ( stat( realPath.c_str(), &st ) < 0 )
		{
			if ( client->httpRequest.location->autoindex )
				throw new DirectoryListing( client );
			else
				throw new Error( client, 403 );
		}
		if ( S_ISDIR( st.st_mode ) )
			throw new Error( client, 403 );
	}
	if ( access( realPath.c_str(), R_OK ) < 0 )
		throw new Error( client, 403 );
	headers["Content-Length"] = utils::conv::toStr< off_t >( st.st_size );
	headers["Content-Type"]	  = parser::extToMimeType( parser::fileExt( realPath ) );
	status					  = 200;
	client->deliverData		  = getFirstLine() + parser::mapToHeaders( headers );

	if ( client->httpRequest.method == "HEAD" )
		currentState = DONE;
	else
		currentState = BODY;
}
