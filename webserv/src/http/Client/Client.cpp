/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:00:32 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/15 13:18:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Client.hpp"

namespace webserv
{
namespace http
{

Client::Client( void )
: fd(-1), isConnectionClose(false), lastActivity(0), deliverOffset(0), deliverData(""), receiveData(""), addr(""), parserRequest(this), httpRequest(), handler(0), server(0), controller(0)
{
	clear();
}

Client::Client( Client const& other )
: parserRequest(other.parserRequest), handler(0)
{
	*this = other;
}

Client::~Client()
{
	if (handler)
	{
		delete handler;
		handler = 0;
	}
}

Client& Client::operator=( Client const& other )
{
	if ( this != &other )
	{
		fd = other.fd;
		isConnectionClose = other.isConnectionClose;
		lastActivity = other.lastActivity;
		deliverOffset = other.deliverOffset;
		deliverData = other.deliverData;
		receiveData = other.receiveData;
		addr = other.addr;
		parserRequest = other.parserRequest;
		parserRequest.client = this;
		httpRequest = other.httpRequest;
		if (handler)
		{
			delete handler;
			handler = 0;
		}
		if (other.handler)
			handler = other.handler->clone(this);
		server = other.server;
		controller = other.controller;
	}
	return *this;
}

}  // namespace http

}  // namespace webserv
