/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redirection.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:01:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 16:54:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Redirection.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Redirection::Redirection( Client* client, int short status, std::string const& uri )
	: Handler( client ), uri_( uri )
{
	this->status = status;
}

Redirection::Redirection( Redirection const& other ) : Handler( other )
{
	*this = other;
}

Redirection::~Redirection() {}

Redirection& Redirection::operator=( Redirection const& other )
{
	Handler::operator=( other );
	if ( this != &other )
		uri_ = other.uri_;
	return *this;
}

Handler* Redirection::clone( http::Client* client )
{
	Redirection *clone(new Redirection(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
