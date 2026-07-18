/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 16:02:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Redirection.hpp"
#include "../../../../inc/hpp/http/Client.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"

void webserv::http::handler::Redirection::build( void ) throw()
{
	std::string host;
	if ( client->httpRequest.version == "HTTP/1.1" )
		host = client->httpRequest.headers["Host"];
	if (host.empty())
		host = client->server->addr;
	if (host.empty())
		host = "0.0.0.0";
	headers["Connection"] = "close";
	headers["Location"] = "http://" + host + uri_;
	client->deliverData = getFirstLine() + parser::mapToHeaders( headers );
	currentState		= DONE;
}
