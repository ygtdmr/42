/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redirection.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkayadib <zkayadib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:54:39 by zkayadib          #+#    #+#             */
/*   Updated: 2026/08/07 18:54:41 by zkayadib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEBSERV_HTTP_HANDLER_REDIRECTION_HPP
#define WEBSERV_HTTP_HANDLER_REDIRECTION_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Redirection : public Handler
{
	public:
		Redirection( Client* client, int short status, std::string const& uri );
		Redirection( Redirection const& other );
		virtual ~Redirection();
		Redirection& operator=( Redirection const& other );
		Handler* clone( http::Client* client );
		void		 build( void ) throw();

	private:
		std::string uri_;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
