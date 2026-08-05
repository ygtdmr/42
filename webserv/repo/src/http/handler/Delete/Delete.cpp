/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:39:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
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
