/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 04:37:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::process( void )
{
	if ( pollfd.revents & POLLIN )
		receive();
	if ( pollfd.revents & POLLOUT )
		deliver();
}
