/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 18:52:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_HANDLER_HPP
#define WEBSERV_HTTP_HANDLER_HANDLER_HPP

#include "../Response.hpp"

namespace webserv
{

namespace manager
{
	class Client;
}

namespace http
{

namespace handler
{
class Handler : public Response
{
	public:
		Handler(void);
		Handler( Handler const& other );
		virtual ~Handler() = 0;
		Handler& operator=( Handler const& other );
		virtual void build( void ) = 0;

		enum state
		{
			HEADERS,
			BODY,
			DONE
		} currentState;
		manager::Client* client;
		std::string		 realPath;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
