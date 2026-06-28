/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 10:15:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_REQUEST_HPP
#define HTTP_REQUEST_HPP

#include <map>
#include <string>

#define STATE_FIRSTLINE ( 0 )
#define STATE_HEADERS ( 1 )
#define STATE_BODY ( 2 )
#define STATE_CHUNKED ( 3 )
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

		std::string							 method;
		std::string							 uri;
		std::string							 version;
		std::map< std::string, std::string > headers;
		std::string							 body;
		short int							 parseState;
		short int							 errorCode;
		bool								 isBodyChunked;
		size_t								 contentLength;

	private:
		void parseIsBodyChunked( void );
		void parseContentLength( void );
};

#endif
