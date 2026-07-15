/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectoryListing.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 16:55:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_DIRECTORY_LISTING_HPP
#define WEBSERV_HTTP_HANDLER_DIRECTORY_LISTING_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class DirectoryListing : public Handler
{
	public:
		DirectoryListing( Client* client );
		DirectoryListing( DirectoryListing const& other );
		virtual ~DirectoryListing();
		DirectoryListing& operator=( DirectoryListing const& other );
		Handler* clone( http::Client* client );
		void			  build( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
