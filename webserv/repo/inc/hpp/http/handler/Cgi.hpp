/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 12:48:35 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 22:28:07 by yidemir          ###   ########.fr       */
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
		Cgi( Client* client );
		Cgi( Cgi const& other );
		virtual ~Cgi();
		Cgi& operator=( Cgi const& other );
		Handler* clone( http::Client* client );
		void build( void );

	private:
		void setupEnv( void );
		bool execute( void );
		void process( void );

		int					 pipeInFd;
		int					 pipeOutFd;
		pid_t				 pid_;
		size_t				 bodySent;
		std::vector< std::string > envStr_;
		std::vector< char* > env_;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
