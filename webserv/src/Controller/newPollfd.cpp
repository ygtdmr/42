/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newPollfd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 08:57:18 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 14:43:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/Controller.hpp"

void webserv::Controller::newPollFd( int fd, int short event ) throw()
{
	struct pollfd pfd;
	pfd.events	= event;
	pfd.revents = 0;
	pfd.fd		= fd;
	pollfds.push_back( pfd );
}
