/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/handler/Redirection.hpp"
#include "http/Client.hpp"

void webserv::http::handler::Redirection::build( void ) throw()
{
	std::string host;
	if ( client->httpRequest.version == "HTTP/1.1" )
		host = client->httpRequest.headers["Host"];
	if (host.empty())
		host = client->server->addr;
	if (host.empty())
		host = "0.0.0.0";
	headers.set("Connection", "close");
	headers.set("Location", "http://" + host + uri_);
	client->deliverData = getFirstLine() + headers.str();
	currentState		= DONE;
}
