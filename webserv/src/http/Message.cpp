/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:42:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 13:11:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/http/Message.hpp"

namespace webserv
{
namespace http
{

Message::Message( void ) : status( 0 ) {}

Message::Message( Message const& other )
{
	*this = other;
}

Message::~Message() {}

Message& Message::operator=( Message const& other )
{
	if ( this != &other )
	{
		headers = other.headers;
		body	= other.body;
		version = other.version;
		status	= other.status;
	}
	return *this;
}

}  // namespace http

}  // namespace webserv
