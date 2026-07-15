/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:00:32 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 08:42:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Get.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Get::Get( Client* client ) : Handler( client ), fileStream_() {}

Get::Get( Get const& other ) : Handler( other )
{
	*this = other;
}

Get::~Get() {}

Get& Get::operator=( Get const& other )
{
	Handler::operator=( other );
	if ( this != &other )
	{
		fileStream_.close();
		fileStream_.clear();
	}
	return *this;
}

Handler* Get::clone( http::Client* client )
{
	Get *clone(new Get(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
