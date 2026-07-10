/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:42:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:16:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/manager/Manager.hpp"

namespace webserv
{
namespace manager
{

Manager::Manager( void ) {}

Manager::Manager( Manager const& other )
{
	*this = other;
}

Manager::~Manager() {}

Manager& Manager::operator=( Manager const& other )
{
	if ( this != &other )
	{
		pollfd = other.pollfd;
		addr   = other.addr;
	}
	return *this;
}

}  // namespace manager

}  // namespace webserv
