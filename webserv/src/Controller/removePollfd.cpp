/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removePollfd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:00:00 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Controller.hpp"

void webserv::Controller::removePollfd( int fd ) throw()
{
	std::vector< struct pollfd >::iterator it( pollfds.begin() );
	while (it != pollfds.end())
	{
		if ( it->fd == fd )
		{
			pollfds.erase(it);
			break;
		}
		it++;
	}
}
