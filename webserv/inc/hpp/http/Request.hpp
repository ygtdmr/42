/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 20:41:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_REQUEST_HPP
#define WEBSERV_HTTP_REQUEST_HPP

#include "../config/Location.hpp"
#include "Message.hpp"

namespace webserv
{

namespace http
{

class Request : public Message
{
	public:
		Request( void );
		Request( Request const& other );
		virtual ~Request();
		Request& operator=( Request const& other );

		std::string				method;
		std::string				uri;
		std::string				uriPath;
		config::Location const* location;
		size_t					bodySize;
		bool					bodyEof;
		bool					isCgi;
};

}  // namespace http

}  // namespace webserv

#endif
