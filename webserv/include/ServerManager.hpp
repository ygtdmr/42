/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerManager.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:45:46 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 19:11:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MANAGER_HPP
#define SERVER_MANAGER_HPP

#include <poll.h>
#include <sstream>
#include "Client.hpp"
#include "ServerConfig.hpp"

class ServerManager
{
	public:
		ServerManager( void );
		ServerManager( ServerManager const& other );
		~ServerManager();
		ServerManager& operator=( ServerManager const& other );
		void		   run( void );
		void		   setupServers( std::vector< ServerConfig > const& serversConfig );

	private:
		void acceptNewConnection( std::vector< pollfd >::iterator& itPoll );
		void closeConnection( std::vector< pollfd >::iterator& itPoll, std::string const& reason );
		void handleRead( std::vector< pollfd >::iterator& itPoll );
		void handleWrite( std::vector< pollfd >::iterator& itPoll );
		// void   checkTimeouts( void );
		int	   setupSocket( ServerConfig const& serverConfig );
		pollfd toPollFd( int fd );

		std::vector< pollfd >*				  pollFds_;
		std::map< int, Client >*			  clients_;
		std::map< int, ServerConfig const* >* servers_;
};

#endif
