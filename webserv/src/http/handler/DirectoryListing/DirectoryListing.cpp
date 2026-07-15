/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectoryListing.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:01:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 16:54:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/DirectoryListing.hpp"

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
