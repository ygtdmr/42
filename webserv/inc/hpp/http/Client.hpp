/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 15:20:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_CLIENT_HPP
#define WEBSERV_HTTP_CLIENT_HPP

#include <ctime>
#include "../Controller.hpp"
#include "../http/Request.hpp"
#include "../http/handler/Handler.hpp"
#include "../parser/Request.hpp"
#include "Server.hpp"

namespace webserv
{

class Controller;

namespace http
{
class Client
{
	public:
		Client( void );
		Client( Client const& other );
		~Client();
		Client& operator=( Client const& other );
		void	process( void );

		int				   fd;
		bool			   isConnectionClose;
		std::time_t		   lastActivity;
		size_t			   deliverOffset;
		std::string		   deliverData;
		std::string		   receiveData;
		std::string		   addr;
		parser::Request	   parserRequest;
		http::Request	   httpRequest;
		handler::Handler*	   handler;
		Server const*	   server;
		Controller *  controller;
		std::vector< int > cgiFds;

	private:
		void receive( void );
		void deliver( void );
		void clear( void );
};
}  // namespace http

}  // namespace webserv

#endif
