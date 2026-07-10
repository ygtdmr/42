/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redirection.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 09:12:14 by yidemir          ###   ########.fr       */
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
		Redirection( manager::Client* client, int short status, std::string const& uri );
		Redirection( Redirection const& other );
		virtual ~Redirection();
		Redirection& operator=( Redirection const& other );
		void		 build( void ) throw();

	private:
		std::string uri_;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
