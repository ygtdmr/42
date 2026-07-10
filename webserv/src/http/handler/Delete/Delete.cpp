/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:39:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:40:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Delete.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Delete::Delete( manager::Client* client ) : Handler( client ) {}

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

}  // namespace handler

}  // namespace http

}  // namespace webserv
