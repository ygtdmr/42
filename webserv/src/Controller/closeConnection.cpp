/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeConnection.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 23:30:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/http/Log.hpp"

void	webserv::Controller::closeConnection( std::vector< http::Client >::iterator& itClient, char const* reason ) throw()
{
	if (itClient->fd < 0)
		return;
	http::Log( *itClient->server, "WARNING" ) << "Connection closed from: " << itClient->addr
										   << ", assigned socket: " << itClient->fd << ", reason: " << reason << '\n';
	close(itClient->fd);
	removePollfd(itClient->fd);
	itClient = clients.erase(itClient);
}
