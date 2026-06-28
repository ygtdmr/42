/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 08:53:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <netinet/in.h>
#include <ctime>
#include <string>
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "ServerConfig.hpp"

class Client
{
	public:
		Client( ServerConfig const& serverConfig );
		Client( Client const& other );
		~Client();
		Client& operator=( Client const& other );
		bool	parseRequest( void );
		void	clear( void );

		sockaddr_in			address;
		std::string			requestBuffer;
		std::string			responseBuffer;
		time_t				lastActivity;
		HttpRequest*		request;
		HttpResponse*		response;
		ServerConfig const& serverConfig;
};

#endif
