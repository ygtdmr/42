/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:55:24 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:55:25 by zkayadib         ###   ########.fr       */
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
	if ( uri_.find("http://") == 0 || uri_.find("https://") == 0 )
		headers.set("Location", uri_);
	else
	{
		if ( uri_[0] != '/' )
			uri_.insert(0, "/");
		headers.set("Location", "http://" + host + uri_);
	}
	client->deliverData = getFirstLine() + headers.str();
	currentState		= DONE;
}
