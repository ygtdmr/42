/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:20:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 14:51:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/handler/Cgi.hpp"
#include "../../../inc/hpp/http/handler/Delete.hpp"
#include "../../../inc/hpp/http/handler/Error.hpp"
#include "../../../inc/hpp/http/handler/Exception.hpp"
#include "../../../inc/hpp/http/handler/Get.hpp"
#include "../../../inc/hpp/http/handler/Head.hpp"
#include "../../../inc/hpp/http/handler/Post.hpp"
#include "../../../inc/hpp/parser/Handler.hpp"

void webserv::parser::Handler::parse( manager::Client const* client )
{
	try
	{
		if ( client->httpRequest.status )
			throw http::handler::Exception( 400 );
		config::Location const* location;
		location = matchLocation( client->httpRequest.uriPath, client->server->config->locations );
		if ( !location )
			throw http::handler::Exception( 404 );
		if ( !location->cgi.empty() )
			handler_ = new http::handler::Cgi();
		else if ( client->httpRequest.method == "GET" )
			handler_ = new http::handler::Get();
		else if ( client->httpRequest.method == "POST" )
			handler_ = new http::handler::Post();
		else if ( client->httpRequest.method == "DELETE" )
			handler_ = new http::handler::Delete();
		else if ( client->httpRequest.method == "HEAD" )
			handler_ = new http::handler::Head();
		else
			throw http::handler::Exception( 404 );
		handler_->client   = client;
		handler_->location = location;
	}
	catch ( http::handler::Exception const& e )
	{
		handler_ = new http::handler::Error( e.status );
	}
}
