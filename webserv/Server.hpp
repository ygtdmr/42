/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:28:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/19 17:22:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include <poll.h>
#include "Config.hpp"

class Server
{
	public:
		Server( std::vector<ServerConfig>& serversConfig );
		Server( Server const& other );
		~Server();
		Server						&operator=( Server const& other );
		void						run( void );
		void						setup( void );
	private:
		void						throwError( std::string const& msg ) const;
		void						setupSocket( void );
		void						setupPoll( int fd );

		std::vector<ServerConfig>					&serversConfig_;
		ServerConfig								&serverConfig_;
		std::vector<int>							listenSockets_;
		std::vector<struct pollfd>					pollFds_;
};

#endif
