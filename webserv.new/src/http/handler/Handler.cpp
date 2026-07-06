/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 18:42:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:13:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/handler/Handler.hpp"

namespace webserv
{
namespace http
{
namespace handler
{

Handler::Handler( void ) {}

Handler::Handler( Handler const& other ): Response(other)
{
	*this = other;
}

Handler::~Handler() {}

Handler& Handler::operator=( Handler const& other )
{
	if ( this != &other )
	{
		realPath = other.realPath;
		client   = other.client;
	}
	return *this;
}

} // namespace handler

}  // namespace manager

}  // namespace webserv
