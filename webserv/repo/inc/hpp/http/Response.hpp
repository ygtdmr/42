/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 08:16:50 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 12:46:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_RESPONSE_HPP
#define WEBSERV_HTTP_RESPONSE_HPP

#include "Message.hpp"

namespace webserv
{

namespace http
{

class Response : public Message
{
	public:
		Response( void );
		Response( Response const& other );
		virtual ~Response();
		Response& operator=( Response const& other );

	protected:
		std::string getFirstLine( void ) const;
};

}  // namespace http

}  // namespace webserv

#endif
