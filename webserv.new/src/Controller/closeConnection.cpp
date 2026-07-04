/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeConnection.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 18:16:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hpp/Controller.hpp"
#include "unistd.h"

namespace webserv
{

void Controller::closeConnection( size_t index ) const
{
	close( ( *pollfds_ )[index].fd );
	pollfds_->erase( pollfds_->begin() + index );
	connections_->erase( connections_->begin() + index );
}

}  // namespace webserv
