/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:04:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 09:07:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Error.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Error::Error( manager::Client* client, int short status ) : Handler( client )
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
	}
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
