/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 18:42:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_MESSAGE_HPP
#define WEBSERV_HTTP_MESSAGE_HPP

#include "Headers.hpp"

namespace webserv
{

namespace http
{

class Message
{
	public:
		Message( void );
		Message( Message const& other );
		virtual ~Message() = 0;
		Message& operator=( Message const& other );

		Headers								 headers;
		std::string							 body;
		std::string							 version;
		int short							 status;
};

}  // namespace http

}  // namespace webserv

#endif
