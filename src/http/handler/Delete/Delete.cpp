/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:55:03 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:55:04 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/handler/Delete.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Delete::Delete( http::Client* client ) : Handler( client ) {}

Delete::Delete( Delete const& other ) : Handler( other )
{
	*this = other;
}

Delete::~Delete() {}

Delete& Delete::operator=( Delete const& other )
{
	Handler::operator=( other );
	return *this;
}

Handler* Delete::clone( http::Client* client )
{
	Delete *clone(new Delete(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
