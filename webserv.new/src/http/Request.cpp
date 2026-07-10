/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:44:43 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/09 15:19:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/http/Request.hpp"

namespace webserv
{
namespace http
{
Request::Request( void ) : location( 0 ), isCgi( false ) {}

Request::Request( Request const& other ) : Message( other )
{
	*this = other;
}
Request& Request::operator=( Request const& other )
{
	if ( this != &other )
	{
		headers	 = other.headers;
		body	 = other.body;
		version	 = other.version;
		status	 = other.status;
		method	 = other.method;
		uri		 = other.uri;
		uriPath	 = other.uriPath;
		location = other.location;
	}
	return *this;
}
Request::~Request() {}
}  // namespace http

}  // namespace webserv
