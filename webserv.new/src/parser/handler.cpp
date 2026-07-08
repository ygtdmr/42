/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:20:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:48:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/handler.hpp"
#include "../../inc/hpp/http/Exception.hpp"
#include "../../inc/hpp/http/handler/Error.hpp"
#include "../../inc/hpp/http/handler/Get.hpp"
#include "../../inc/hpp/http/handler/Upload.hpp"
#include "../../inc/hpp/http/handler/Delete.hpp"
#include "../../inc/hpp/http/handler/Redirection.hpp"

void webserv::parser::handler( manager::Client* client )
{
	if ( client->httpRequest.status >= 400 )
		client->handler = new http::handler::Error( client, client->httpRequest.status );
	else if ( client->httpRequest.location->redirect.first > 0 )
	{
		std::pair< int short, std::string > const& redirect( client->httpRequest.location->redirect );
		client->handler = new http::handler::Redirection( client, redirect.first, redirect.second );
	}
	else if ( client->httpRequest.method == "GET" || client->httpRequest.method == "HEAD" )
		client->handler = new http::handler::Get( client );
	else if ( client->httpRequest.method == "POST" )
		client->handler = new http::handler::Upload( client );
	else if ( client->httpRequest.method == "DELETE" )
		client->handler = new http::handler::Delete( client );
	else
		client->handler = new http::handler::Error( client, 404 );
}
