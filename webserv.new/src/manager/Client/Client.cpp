/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:00:32 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:32:05 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"

namespace webserv
{
namespace manager
{

Client::Client( void ) : isConnectionClose(false), handler( 0 )
{
	clear();
}

Client::Client( Client const& other ): Manager(other)
{
	*this = other;
}

Client::~Client() {}

Client& Client::operator=( Client const& other )
{
	if ( this != &other )
	{
		isConnectionClose = other.isConnectionClose;
		server			  = other.server;
		receiveData		  = other.receiveData;
		deliverData		  = other.deliverData;
		parserRequest	  = other.parserRequest;
		httpRequest		  = other.httpRequest;
		handler			  = other.handler;
	}
	return *this;
}

}  // namespace manager

}  // namespace webserv
