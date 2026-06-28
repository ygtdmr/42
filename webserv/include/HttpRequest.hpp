/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/28 11:45:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <map>
#include <string>
#include "ServerConfig.hpp"

#define STATE_HEADERS ( 0 )
#define STATE_BODY ( 1 )
#define STATE_CHUNKED ( 2 )
#define STATE_VALIDATE ( 3 )
#define STATE_DONE ( 4 )

class HttpRequest
{
	public:
		HttpRequest( void );
		HttpRequest( HttpRequest const& other );
		~HttpRequest();

		HttpRequest& operator=( HttpRequest const& other );
		void		 parseFirstLine( std::string const& line );
		void		 parseHeaders( std::string const& data );
		void		 parseBody( std::string const& data );
		void		 unchunkBody( std::string& data );
		void		 validate( ServerConfig const& serverConfig );

		int short							 parseState;
		int short							 errorCode;
		bool								 isBodyChunked;
		bool								 isDirectoryListing;
		size_t								 contentLength;
		std::string							 method;
		std::string							 uri;
		std::string							 version;
		std::map< std::string, std::string > headers;
		std::string							 body;
		LocationConfig const*				 locationConfig;

	private:
		void parseIsBodyChunked( void );
		void parseIsDirectoryListing( void );
		void parseContentLength( void );
};

#endif
