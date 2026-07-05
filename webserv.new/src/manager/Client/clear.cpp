/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 08:50:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/manager/Client.hpp"

void webserv::manager::Client::clear( void )
{
	receiveData = std::string();
	deliverData = std::string();

	httpRequest = http::Request();

	parserRequest			  = parser::Request();
	parserRequest.receiveData = &receiveData;
	parserRequest.request	  = &httpRequest;

	if ( handler )
	{
		delete handler;
		handler = 0;
	}
}
