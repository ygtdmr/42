/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 13:51:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/Client.hpp"
#include "../../../../inc/hpp/parser/extToMimeType.hpp"
#include "../../../../inc/hpp/parser/fileExt.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/parser/statusToReasonPhrase.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"

void webserv::http::handler::Error::buildHeaders( void ) throw()
{
	struct stat st;
	client->deliverData = getFirstLine();
	if ( status == 400 || status == 413 || status == 408 || status == 500 || status == 503 || status == 504 )
		headers["Connection"] = "close";
	if ( client->server->config->errorPages.find( status ) != client->server->config->errorPages.end() )
	{
		errorPagePath = client->server->config->errorPages.find( status )->second;
		if ( !stat( errorPagePath.c_str(), &st ) )
		{
			headers["Content-Length"] = utils::conv::toStr< off_t >( st.st_size );
			headers["Content-Type"]	  = parser::extToMimeType( parser::fileExt( errorPagePath ) );
			client->deliverData += parser::mapToHeaders( headers );
		}
		else
		{
			headers["Content-Type"] = "text/html";
			errorPagePath			= "";
		}
	}
	else
		headers["Content-Type"] = "text/html";
	if ( !errorPagePath.empty() && client->httpRequest.method == "HEAD" )
		currentState = DONE;
	else
		currentState = BODY;
}
