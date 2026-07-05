/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Head.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:56 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 12:54:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_HEAD_HPP
#define WEBSERV_HTTP_HANDLER_HEAD_HPP

#include "IHandler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Head : public IHandler
{
	public:
		Head( void );
		Head( Head const& other );
		virtual ~Head();
		Head& operator=( Head const& other );
		void  build( void ) const;
		void  buildHeaders( void );
		void  buildBody( void );

		config::Location location;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
