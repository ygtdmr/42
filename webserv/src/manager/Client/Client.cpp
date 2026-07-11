/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:00:32 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 08:57:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"

namespace webserv
{
namespace manager
{

Client::Client( void ) : isConnectionClose( false ), socketFd( -1 ), deliverOffset( 0 ), handler( 0 )
{
	clear();
}

Client::Client( Client const& other ) : Manager( other )
{
	*this = other;
}

Client::~Client()
{
	if ( handler )
		delete handler;
}

Client& Client::operator=( Client const& other )
{
	if ( this != &other )
	{
		isConnectionClose = other.isConnectionClose;
		socketFd		  = other.socketFd;
		server			  = other.server;
		receiveData		  = other.receiveData;
		deliverData		  = other.deliverData;
		deliverOffset	  = other.deliverOffset;
		parserRequest	  = other.parserRequest;
		httpRequest		  = other.httpRequest;
		handler			  = other.handler;
	}
	return *this;
}

}  // namespace manager

}  // namespace webserv
