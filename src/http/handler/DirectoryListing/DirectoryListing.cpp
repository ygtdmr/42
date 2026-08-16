/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectoryListing.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:55:17 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:55:19 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/handler/DirectoryListing.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

DirectoryListing::DirectoryListing( http::Client* client ) : Handler( client ) {}

DirectoryListing::DirectoryListing( DirectoryListing const& other ) : Handler( other )
{
	*this = other;
}

DirectoryListing::~DirectoryListing() {}

DirectoryListing& DirectoryListing::operator=( DirectoryListing const& other )
{
	Handler::operator=( other );
	return *this;
}

Handler* DirectoryListing::clone( http::Client* client )
{
	DirectoryListing *clone(new DirectoryListing(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
