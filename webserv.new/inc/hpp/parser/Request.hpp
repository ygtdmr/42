/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:47:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 19:26:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_REQUEST_HPP
#define WEBSERV_PARSER_REQUEST_HPP

#include <string>
#include "../http/Request.hpp"

namespace webserv
{
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

		std::string*   receiveData;
		http::Request* request;
		enum state
		{
			REQUEST_FIRST_LINE,
			HEADERS,
			CHUNKED_BODY,
			BODY,
			DONE
		} currentState;

	private:
		bool isBodyDone() const;
		bool isChunkedBodyDone( std::string const& data ) const;
};

}  // namespace parser
}  // namespace webserv

#endif
