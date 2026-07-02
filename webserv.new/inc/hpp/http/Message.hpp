/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 18:14:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_MESSAGE_HPP
#define WEBSERV_HTTP_MESSAGE_HPP

#include <map>
#include <string>

namespace webserv
{

namespace http
{

class Message
{
	public:
		Message( void );
		Message( Message const& other );
		virtual ~Message()								   = 0;
		virtual Message& operator=( Message const& other ) = 0;

		std::map< std::string, std::string > headers;
		std::string							 body;
		std::string							 version;
		int short							 status;
};

}  // namespace http

}  // namespace webserv

#endif
