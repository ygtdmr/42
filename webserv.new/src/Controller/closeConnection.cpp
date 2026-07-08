/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeConnection.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 10:16:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/ServerLog.hpp"
#include "../../inc/hpp/manager/Client.hpp"
#include "unistd.h"

namespace webserv
{

void Controller::closeConnection( size_t index, char const* reason ) const throw()
{
	struct pollfd const& pfd( ( *pollfds_ )[index] );
	std::string const&	 addr( ( *connections_ )[index]->addr );
	close( pfd.fd );
	ServerLog( ( *connections_ )[index], "WARNING" )
		<< "Connection closed from: " << addr << ", assigned socket: " << pfd.fd << ", reason: " << reason
		<< '\n';
	pollfds_->erase( pollfds_->begin() + index );
	delete *( connections_->begin() + index );
	connections_->erase( connections_->begin() + index );
}

}  // namespace webserv
