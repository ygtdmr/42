/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Upload.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:33:43 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/handler/Upload.hpp"
#include "http/Client.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Upload::Upload( Client* client ) : Handler( client ), fileNames_(), uploadPath_("")
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
	if ( this != &other )
	{
		fileNames_ = other.fileNames_;
		uploadPath_ = other.uploadPath_;
	}
	return *this;
}

Handler* Upload::clone( http::Client* client )
{
	Upload *clone(new Upload(*this));
	clone->client = client;
	return clone;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
