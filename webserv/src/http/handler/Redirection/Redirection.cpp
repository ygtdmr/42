/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redirection.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:01:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 09:16:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Redirection.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Redirection::Redirection( manager::Client* client, int short status, std::string const& uri )
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

}  // namespace handler

}  // namespace http

}  // namespace webserv
