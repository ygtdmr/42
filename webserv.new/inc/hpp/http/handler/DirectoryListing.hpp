/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectoryListing.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 12:36:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_GET_HPP
#define WEBSERV_HTTP_HANDLER_GET_HPP

#include "IHandler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class DirectoryListing : public IHandler
{
	public:
		DirectoryListing( void );
		DirectoryListing( DirectoryListing const& other );
		virtual ~DirectoryListing();
		DirectoryListing& operator=( DirectoryListing const& other );
		void buildBody( void );
		void buildHeaders( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
