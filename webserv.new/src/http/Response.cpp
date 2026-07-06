/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:54:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:13:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/http/Response.hpp"

namespace webserv
{
	namespace http
	{
		Response::Response( void ) {}
		Response::Response( Response const& other ): Message(other)
		{
			*this = other;
		}
		Response& Response::operator=( Response const& other )
		{
			if ( this != &other )
			{
				headers = other.headers;
				body = other.body;
				version = other.version;
				status = other.status;
			}
			return *this;
		}
		Response::~Response() {}
	} // namespace http
	
} // namespace webserv
