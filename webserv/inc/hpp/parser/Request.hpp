/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:47:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/09 11:08:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_REQUEST_HPP
#define WEBSERV_PARSER_REQUEST_HPP

namespace webserv
{
namespace manager
{
class Client;
}

namespace parser
{

class Request
{
	public:
		Request( void );
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
		manager::Client* client;

	private:
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
