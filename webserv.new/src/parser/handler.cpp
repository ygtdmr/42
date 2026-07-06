/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:20:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 13:36:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/handler.hpp"
#include "../../inc/hpp/http/Exception.hpp"
// #include "../../inc/hpp/http/handler/Cgi.hpp"
// #include "../../inc/hpp/http/handler/Delete.hpp"
#include "../../inc/hpp/http/handler/Error.hpp"
#include "../../inc/hpp/http/handler/Get.hpp"
// #include "../../inc/hpp/http/handler/Head.hpp"
// #include "../../inc/hpp/http/handler/Post.hpp"
#include "../../inc/hpp/utils/map.hpp"

static void setupHandler( webserv::manager::Client* client )
{
	std::string root;
	root = client->httpRequest.location->root;
	if ( root.empty() )
		root = client->server->config->root;
	client->handler->realPath = root + client->httpRequest.uriPath;
	client->handler->client	  = client;
	client->handler->version  = client->httpRequest.version;
	if ( client->httpRequest.version == "HTTP/1.1" )
	{
		if ( webserv::utils::map::has< std::string, std::string >( client->httpRequest.headers,
																   "Connection" ) )
			client->handler->headers["Connection"] = client->httpRequest.headers["Connection"];
		else
			client->handler->headers["Connection"] = "keep-alive";
	}
	else
		client->handler->headers["Connection"] = "close";
}

void webserv::parser::handler( manager::Client* client )
{
	try
	{
		if ( client->httpRequest.status >= 400 )
			throw http::Exception( client->httpRequest.status );
		// if ( !client->httpRequest.location->cgi.empty() )
		// 	client->handler = new http::handler::Cgi();
		// else if...
		if ( client->httpRequest.method == "GET" )
			client->handler = new http::handler::Get();
		// else if ( client->httpRequest.method == "POST" )
		// 	client->handler = new http::handler::Post();
		// else if ( client->httpRequest.method == "DELETE" )
		// 	client->handler = new http::handler::Delete();
		// else if ( client->httpRequest.method == "HEAD" )
		// 	client->handler = new http::handler::Head();
		else
			throw http::Exception( 404 );
		setupHandler( client );
	}
	catch ( http::Exception const& e )
	{
		client->handler = new http::handler::Error( e.status );
	}
}
