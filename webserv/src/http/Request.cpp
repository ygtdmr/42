/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:44:43 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 20:00:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/http/Request.hpp"

namespace webserv
{
namespace http
{
Request::Request( void ): Message(), method(""), uri(""), uriPath(""), cgiBin(""), location(0), bodySize(0), bodyEof(false) {}

Request::Request( Request const& other ) : Message( other )
{
	*this = other;
}
Request& Request::operator=( Request const& other )
{
	Message::operator=(other);
	if ( this != &other )
	{
		method	 = other.method;
		uri		 = other.uri;
		uriPath	 = other.uriPath;
		cgiBin	 = other.cgiBin;
		location = other.location;
		bodySize = other.bodySize;
		bodyEof = other.bodyEof;
	}
	return *this;
}
Request::~Request() {}
}  // namespace http

}  // namespace webserv
