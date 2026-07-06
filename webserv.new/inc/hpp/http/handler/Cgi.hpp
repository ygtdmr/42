/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:35 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:50:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_CGI_HPP
#define WEBSERV_HTTP_HANDLER_CGI_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Cgi : public Handler
{
	public:
		Cgi( void );
		Cgi( Cgi const& other );
		virtual ~Cgi();
		Cgi& operator=( Cgi const& other );
		void build( void );
		void buildHeaders( void );
		void buildBody( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
