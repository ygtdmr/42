/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removePollfd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:00:00 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/13 23:08:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"

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
