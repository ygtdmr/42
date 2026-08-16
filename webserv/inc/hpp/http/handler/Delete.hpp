/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:54:18 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:54:20 by zkayadib         ###   ########.fr       */
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
		Delete( Client* client );
		Delete( Delete const& other );
		virtual ~Delete();
		Delete& operator=( Delete const& other );
		Handler* clone( http::Client* client );
		void	build( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
