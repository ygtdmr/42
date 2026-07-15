/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:48:40 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 22:48:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONTROLLER_HPP
#define WEBSERV_CONTROLLER_HPP

#include <poll.h>
#include <vector>
#include "config/Server.hpp"
#include "http/Client.hpp"
#include "http/Server.hpp"

namespace webserv
{

	namespace http
	{
		class Client;
	}

class Controller
{
	public:
		Controller( void );
		Controller( Controller const& other );
		~Controller();
		Controller& operator=( Controller const& other );
		void		acceptConnection( http::Server const& server ) throw();
		void		closeConnection( std::vector< http::Client >::iterator& itClient, char const* reason ) throw();
		void		setup( std::vector< config::Server > const& servers );
		void		run( void ) throw();
		void removePollfd( int fd ) throw();
		void newPollFd( int fd, int short event = POLLIN ) throw();
		struct pollfd& getPollfd( int fd );

		std::vector< struct pollfd >  pollfds;
		std::vector< http::Server >	  servers;
		std::vector< http::Client >	  clients;

	private:
		void setupServer( config::Server const* config, char const* host, char const* port );
};

}  // namespace webserv

#endif
