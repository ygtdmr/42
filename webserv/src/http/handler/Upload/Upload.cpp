/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Upload.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:33:43 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 20:02:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Upload.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Upload::Upload( manager::Client* client ) : Handler( client )
{
	uploadPath_ = client->httpRequest.location->uploadDir + '/';
}

Upload::Upload( Upload const& other ) : Handler( other )
{
	*this = other;
}

Upload::~Upload() {}

Upload& Upload::operator=( Upload const& other )
{
	Handler::operator=( other );
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
