/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:47:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 19:17:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_REQUEST_HPP
#define WEBSERV_PARSER_REQUEST_HPP

#include <string>

namespace webserv
{
namespace http
{
class Client;
}

namespace parser
{

class Request
{
	public:
		Request( http::Client *client );
		Request( Request const& other );
		~Request();
		Request& operator=( Request const& other );
		void	 parse( void );

		enum state
		{
			REQUEST_FIRST_LINE,
			LOCATION,
			HEADERS,
			CHUNKED_BODY,
			BODY,
			DONE
		} currentState;
		http::Client* client;
		std::string		 chunkedBuffer;

	private:
		size_t		contentLength_;

		void parseFirstLine( void );
		void parseLocation( void );
		void parseIsCgi( void );
		void parseHeaders( void );
		void parseChunkedBody( void );
		void parseBody( void );
		void checkMaxBodySize( void );
};

}  // namespace parser
}  // namespace webserv

#endif
