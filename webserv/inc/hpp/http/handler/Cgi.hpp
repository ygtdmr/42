/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:35 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 10:47:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_CGI_HPP
#define WEBSERV_HTTP_HANDLER_CGI_HPP

#include <unistd.h>
#include <vector>
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
		Cgi( manager::Client* client );
		Cgi( Cgi const& other );
		virtual ~Cgi();
		Cgi& operator=( Cgi const& other );
		void build( void );

	private:
		void setupEnv( void );
		bool execute( void );

		int					 pipeInFd;
		int					 pipeOutFd;
		pid_t				 pid_;
		std::vector< char* > env_;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
