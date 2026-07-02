/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:28:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 18:08:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"

webserv::parser::Request::Request( void ) : currentState( REQUEST_FIRST_LINE ) {}

webserv::parser::Request::Request( Request const& other )
{
	*this = other;
}

webserv::parser::Request::~Request() {}

webserv::parser::Request& webserv::parser::Request::operator=( webserv::parser::Request const& other )
{
	if ( this != &other )
	{
		currentState = other.currentState;
		*request	 = *other.request;
		*receiveData = *other.receiveData;
	}
	return *this;
}
