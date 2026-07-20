/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:04:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Client.hpp"

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
