/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Head.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:56 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:50:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_HEAD_HPP
#define WEBSERV_HTTP_HANDLER_HEAD_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Head : public Handler
{
	public:
		Head( void );
		Head( Head const& other );
		virtual ~Head();
		Head& operator=( Head const& other );
		void  build( void );
		void  buildHeaders( void );
		void  buildBody( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
