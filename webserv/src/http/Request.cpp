/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:44:43 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/16 14:51:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/http/Request.hpp"

namespace webserv
{
namespace http
{
Request::Request( void ): method(""), uri(""), uriPath(""), cgiExt(""), location(0), bodySize(0), bodyEof(false) {}

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
		cgiExt	 = other.cgiExt;
		location = other.location;
		bodySize = other.bodySize;
		bodyEof = other.bodyEof;
	}
	return *this;
}
Request::~Request() {}
}  // namespace http

}  // namespace webserv
