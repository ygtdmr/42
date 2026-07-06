/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMessage.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:40:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_IMESSAGE_HPP
#define WEBSERV_HTTP_IMESSAGE_HPP

#include <map>
#include <string>

namespace webserv
{

namespace http
{

class Message
{
	public:
		virtual ~Message() = 0;

		std::map< std::string, std::string > headers;
		std::string							 body;
		std::string							 version;
		int short							 status;
};

}  // namespace http

}  // namespace webserv

#endif
