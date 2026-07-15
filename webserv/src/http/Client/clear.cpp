/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/15 13:19:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Client.hpp"

void webserv::http::Client::clear( void )
{
	receiveData.clear();
	deliverData.clear();
	receiveData	  = "";
	deliverData	  = "";
	
	deliverOffset = 0;

	httpRequest			 = http::Request();
	parserRequest		 = parser::Request(this);

	if ( handler )
	{
		delete handler;
		handler = 0;
	}
}
