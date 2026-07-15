/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPollfd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 21:53:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"
#include "../../inc/hpp/utils/conv.hpp"
#include <stdexcept>

struct pollfd& webserv::Controller::getPollfd( int fd )
{
	std::vector< struct pollfd >::iterator it(pollfds.begin());
	while (it != pollfds.end())
	{
		if ( it->fd == fd )
			return *it;
		it++;
	}
	throw std::runtime_error("pollfd not found, fd: " + utils::conv::toStr<int>(fd));
}
