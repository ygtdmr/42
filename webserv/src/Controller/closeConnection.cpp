/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeConnection.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 17:21:26 by yidemir          ###   ########.fr       */
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
	std::string const&	 addr( ( *connections )[index]->addr );
	close( pfd.fd );
	ServerLog( ( *connections )[index], "WARNING" )
		<< "Connection closed from: " << addr << ", assigned socket: " << pfd.fd << ", reason: " << reason
		<< '\n';
	pollfds->erase( pollfds->begin() + index );
	delete *( connections->begin() + index );
	connections->erase( connections->begin() + index );
}

}  // namespace webserv
