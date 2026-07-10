/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:01:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/09 15:03:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Cgi.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Cgi::Cgi( manager::Client* client ) : Handler( client ), indexClient( -1 ), isExec_( false ) {}

Cgi::Cgi( Cgi const& other ) : Handler( other )
{
	*this = other;
}

Cgi::~Cgi()
{
	for ( size_t i = 0; i < ( env_.size() - 1 ); i++ )
		delete[] env_[i];
}

Cgi& Cgi::operator=( Cgi const& other )
{
	Handler::operator=( other );
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
