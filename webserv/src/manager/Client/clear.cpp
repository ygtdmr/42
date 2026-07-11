/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 12:33:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::clear( void )
{
	receiveData = std::string();
	deliverData = std::string();
	deliverOffset = 0;

	httpRequest			 = http::Request();
	parserRequest		 = parser::Request();
	parserRequest.client = this;

	if ( handler )
	{
		delete handler;
		handler = 0;
	}
}
