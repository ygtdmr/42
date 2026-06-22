/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 19:44:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/21 20:57:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "Config.hpp"

#define CLIENT_READ_BUFFER 4096

class Client
{
	public:
		Client( ServerConfig& serverConfig );
		Client( Client const& other );
		~Client();
		Client								&operator=( Client const& other );
		void								read( char const* buffer, int bytesRead );
		void								parseHeaders( void );

		int									status;
		std::map<std::string, std::string>	headers;
		ServerConfig						&serverConfig;
	private:
		bool								headersParsed_;
		std::string							rawData_;

};

#endif
