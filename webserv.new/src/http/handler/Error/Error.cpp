/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:04:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:10:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Error.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Error::Error( int short status )
{
	this->status = status;
	currentState = HEADERS;
}

Error::Error( Error const& other ): Handler(other)
{
	*this = other;
}

Error::~Error() {}

Error& Error::operator=( Error const& other )
{
	if ( this != &other )
	{
		errorPagePath = other.errorPagePath;
	}
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
