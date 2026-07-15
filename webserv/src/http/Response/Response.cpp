/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:54:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 14:10:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Response.hpp"

namespace webserv
{
namespace http
{
Response::Response( void ) {}
Response::Response( Response const& other ) : Message( other )
{
	*this = other;
}
Response& Response::operator=( Response const& other )
{
	Message::operator=(other);
	return *this;
}
Response::~Response() {}
}  // namespace http

}  // namespace webserv
