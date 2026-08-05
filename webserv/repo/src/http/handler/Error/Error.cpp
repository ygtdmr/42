/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:04:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/handler/Error.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Error::Error( Client* client, int short status ) : Handler( client ), errorPagePath("")
{
	this->status = status;
}

Error::Error( Error const& other ) : Handler( other )
{
	*this = other;
}

Error::~Error() {}

Error& Error::operator=( Error const& other )
{
	Handler::operator=( other );
	if ( this != &other )
	{
		errorPagePath = other.errorPagePath;
		fileStream_.close();
		fileStream_.clear();
	}
	return *this;
}

Handler* Error::clone( http::Client* client )
{
	Error *clone(new Error(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
