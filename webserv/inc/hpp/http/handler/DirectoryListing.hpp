/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectoryListing.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:54:29 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:54:30 by zkayadib         ###   ########.fr       */
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
