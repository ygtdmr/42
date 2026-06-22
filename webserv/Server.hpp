/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:28:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/21 20:26:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include <poll.h>
#include "Response.hpp"

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
		void						throwError( ServerConfig const& serverConfig, std::string const& msg ) const;
		int							setupSocket( ServerConfig const& serverConfig );
		pollfd						toPollFd( int fd );

		std::vector<pollfd>			*pollFds_;
		std::map<int, Client>		*clients_;
		std::map<int, ServerConfig&>*sockets_;
		std::vector<ServerConfig>	&serversConfig_;
};

#endif
