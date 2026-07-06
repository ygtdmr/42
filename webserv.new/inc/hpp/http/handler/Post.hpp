/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Post.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:50:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_POST_HPP
#define WEBSERV_HTTP_HANDLER_POST_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Post : public Handler
{
	public:
		Post( void );
		Post( Post const& other );
		virtual ~Post();
		Post& operator=( Post const& other );
		void  build( void );
		void  buildHeaders( void );
		void  buildBody( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
