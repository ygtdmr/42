/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 12:51:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_ERROR_HPP
#define WEBSERV_HTTP_HANDLER_ERROR_HPP

#include "IHandler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Error : public IHandler
{
	public:
		Error( int short status );
		Error( Error const& other );
		virtual ~Error();
		Error& operator=( Error const& other );
		void   build( void ) const throw();
		void   buildBody( void ) throw();
		void   buildHeaders( void ) throw();
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
