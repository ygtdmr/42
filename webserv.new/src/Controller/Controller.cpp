/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:18:28 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:54:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/Controller.hpp"

namespace webserv
{

Controller::Controller( void )
{
	connections_ = new std::vector< manager::Manager >;
	pollfds_	 = new std::vector< struct pollfd >;
}

Controller::Controller( Controller const& other )
{
	*this = other;
}

Controller::~Controller()
{
	delete connections_;
	delete pollfds_;
}

Controller& Controller::operator=( Controller const& other )
{
	if ( this != &other )
	{
		*connections_ = *other.connections_;
		*pollfds_	  = *other.pollfds_;
	}
	return *this;
}

}  // namespace webserv
