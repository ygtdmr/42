/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 18:33:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_ERROR_HPP
#define WEBSERV_HTTP_HANDLER_ERROR_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Error : public Handler
{
	public:
		Error( int short status );
		Error( Error const& other );
		virtual ~Error();
		Error& operator=( Error const& other );
		void   build( void ) throw();
		void   buildBody( void ) throw();
		void   buildHeaders( void ) throw();
		void   readErrorPageFile( void ) throw();

		std::string	errorPagePath;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
