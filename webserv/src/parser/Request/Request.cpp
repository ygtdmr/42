/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:28:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 11:33:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"

namespace webserv
{
namespace parser
{

Request::Request( void ) : currentState( REQUEST_FIRST_LINE ) {}

Request::Request( Request const& other )
{
	*this = other;
}

Request::~Request() {}

Request& Request::operator=( Request const& other )
{
	if ( this != &other )
	{
		currentState = other.currentState;
		client		 = other.client;
		chunkedBuffer = other.chunkedBuffer;
	}
	return *this;
}

}  // namespace parser
}  // namespace webserv
