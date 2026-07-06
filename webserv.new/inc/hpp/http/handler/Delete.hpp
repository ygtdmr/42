/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:50:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_DELETE_HPP
#define WEBSERV_HTTP_HANDLER_DELETE_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Delete : public Handler
{
	public:
		Delete( void );
		Delete( Delete const& other );
		virtual ~Delete();
		Delete& operator=( Delete const& other );
		void	build( void );
		void	buildHeaders( void );
		void	buildBody( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
