/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "http/handler/Error.hpp"
#include "http/Client.hpp"
#include "parser/extToMimeType.hpp"
#include "parser/fileExt.hpp"
#include "parser/statusToReasonPhrase.hpp"
#include "utils/conv.hpp"

void webserv::http::handler::Error::buildHeaders( void ) throw()
{
	struct stat st;
	client->deliverData = getFirstLine();
	if ( status == 400 || status == 413 || status == 408 || status == 500 || status == 503 || status == 504 )
		headers.set("Connection", "close");
	if ( client->server->config->errorPages.find( status ) != client->server->config->errorPages.end() )
	{
		errorPagePath = client->server->config->errorPages.find( status )->second;
		if ( !stat( errorPagePath.c_str(), &st ) )
		{
			headers.set("Content-Length", utils::conv::toStr< off_t >( st.st_size ));
			headers.set("Content-Type", parser::extToMimeType( parser::fileExt( errorPagePath ) ) );
			client->deliverData += headers.str();
		}
		else
		{
			headers.set("Content-Type", "text/html");
			errorPagePath			= "";
		}
	}
	else
		headers.set("Content-Type", "text/html");
	if ( !errorPagePath.empty() && client->httpRequest.method == "HEAD" )
		currentState = DONE;
	else
		currentState = BODY;
}
