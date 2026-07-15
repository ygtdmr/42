/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:42:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 14:12:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/handler/Handler.hpp"
#include "../../../inc/hpp/http/Client.hpp"

namespace webserv
{
namespace http
{
namespace handler
{

Handler::Handler( Client* client ) : currentState( HEADERS ), realPath(""), client( client )
{
	version = client->httpRequest.version;
	if ( version.empty() )
		version = "HTTP/1.0";
	if ( client->httpRequest.location )
	{
		std::string root;
		root = client->httpRequest.location->root;
		if ( root.empty() )
			root = client->server->config->root;
		realPath =
			root + '/' + client->httpRequest.uriPath.substr( client->httpRequest.location->uriPath.size() );
	}
	headers["Connection"] = "";
	if ( version == "HTTP/1.1" )
		headers["Connection"] = client->httpRequest.headers["Connection"];
	if ( headers["Connection"].empty() )
		headers["Connection"] = "close";
}

Handler::Handler( Handler const& other ) : Response( other )
{
	*this = other;
}

Handler::~Handler() {}

Handler& Handler::operator=( Handler const& other )
{
	Response::operator=(other);
	if ( this != &other )
	{
		realPath = other.realPath;
		client	 = other.client;
		currentState = other.currentState;
	}
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
