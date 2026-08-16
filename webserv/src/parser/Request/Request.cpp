/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:28:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/Request.hpp"

namespace webserv
{
namespace parser
{

Request::Request( http::Client *client ) : currentState( REQUEST_FIRST_LINE ), client(client), chunkedBuffer(""), contentLength_(0) {}

Request::Request( Request const& other )
{
	*this = other;
}

Request::~Request() {}

Request& Request::operator=( Request const& other )
{
	if ( this != &other )
	{
		currentState  = other.currentState;
		client		  = other.client;
		chunkedBuffer = other.chunkedBuffer;
		contentLength_ = other.contentLength_;
	}
	return *this;
}

}  // namespace parser
}  // namespace webserv
