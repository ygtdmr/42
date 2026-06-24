/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 19:44:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/24 09:10:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <netinet/in.h>
#include "Config.hpp"

#define CLIENT_READ_BUFFER 4096

#define CLIENT_STATUS_ERROR_CTL ( 1 << 0 )
#define CLIENT_STATUS_ERROR_BR ( 1 << 1 )
#define CLIENT_STATUS_ERROR_HTTP_V ( 1 << 2 )
#define CLIENT_STATUS_RQ_LINE_OK ( 1 << 3 )
#define CLIENT_STATUS_HEADER_OK ( 1 << 4 )
#define CLIENT_STATUS_CONTENT_READ ( 1 << 5 )
#define CLIENT_STATUS_READ_OK ( 1 << 6 )

class Client
{
	public:
		Client( sockaddr_in addr, ServerConfig& serverConfig );
		Client( Client const& other );
		~Client();
		Client								&operator=( Client const& other );
		void								read( char const* buffer, int bytesRead );
		bool								isReadEnd( void ) const;
		const char							*getContent( void ) const;

		sockaddr_in							addr;
		std::map<std::string, std::string>	headers;
		ServerConfig						&serverConfig;
		char								status;
		std::string							method;
		std::string							requestUri;
		std::string							httpVersion;
	private:
		void								readHeaders( void );
		void								readRequestLine( void );

		std::string							rawData_;
		unsigned long						contentLength_;
		bool								isContentChunked_;

};

#endif
