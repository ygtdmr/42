/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IHandler.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 13:13:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_IHANDLER_HPP
#define WEBSERV_HTTP_HANDLER_IHANDLER_HPP

#include "../../config/Location.hpp"
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
		virtual ~IHandler()				 = 0;
		virtual void build( void ) const = 0;

		manager::Client const*	client;
		config::Location const* location;
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
