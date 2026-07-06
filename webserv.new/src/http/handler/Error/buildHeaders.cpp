/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 18:24:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"
#include "../../../../inc/hpp/utils/map.hpp"
#include "../../../../inc/hpp/parser/extToMimeType.hpp"
#include "../../../../inc/hpp/parser/fileExt.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"

void webserv::http::handler::Error::buildHeaders( void ) throw()
{
	struct stat st;
	if (utils::map::has<int short, std::string>(client->server->config->errorPages, status))
	{
		errorPagePath = client->server->config->errorPages.find(status)->second;
		if ( !stat( errorPagePath.c_str(), &st ) )
		{
			headers["Content-Length"] = utils::conv::toStr< off_t >( st.st_size );
			headers["Content-Type"]	  = parser::extToMimeType( parser::fileExt( realPath ) );
			client->deliverData		  = parser::mapToHeaders( headers );
		}
		else
		{
			headers["Content-Type"] = "text/html";
			errorPagePath = "";
		}
	}
	currentState = BODY;
}
