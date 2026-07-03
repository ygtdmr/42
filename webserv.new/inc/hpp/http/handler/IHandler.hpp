/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IHandler.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/03 13:55:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_IHANDLER_HPP
#define WEBSERV_HTTP_HANDLER_IHANDLER_HPP

#include "../../manager/Client.hpp"
#include "../Response.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class IHandler : public Response
{
	public:
		virtual ~IHandler()								= 0;
		virtual std::string build( void ) const throw() = 0;

		manager::Client client;
		enum state
		{
			DELIVER,
			DONE
		} currentState;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
