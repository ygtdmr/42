/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeConnection.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 13:05:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/ServerLog.hpp"
#include "../../inc/hpp/manager/Client.hpp"

namespace webserv
{

void Controller::closeConnection( size_t index, char const* reason ) const throw()
{
	struct pollfd const& pfd( ( *pollfds )[index] );
	manager::Client*	 client = dynamic_cast< manager::Client* >( ( *connections )[index] );
	std::string const&	 addr( client->addr );
	int					 fd = pfd.fd;

	ServerLog( client->server, "WARNING" ) << "Connection closed from: " << addr
										   << ", assigned socket: " << fd << ", reason: " << reason << '\n';

	manager::Manager* conn = ( *connections )[index];
	close( fd );
	pollfds->erase( pollfds->begin() + index );
	connections->erase( connections->begin() + index );
	delete conn;
}

}  // namespace webserv
