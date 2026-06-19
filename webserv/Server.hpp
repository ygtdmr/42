/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 10:28:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/19 11:05:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "Config.hpp"

class Server
{
	public:
		Server( std::vector<ServerConfig>& serversConfig );
		Server( Server const& other );
		~Server();
		Server	&operator=( Server const& other );
		void	run( void );
	private:
		void	setupSockets( void );
		std::vector<ServerConfig>	&serversConfig_;
};

#endif
