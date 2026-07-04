/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 13:13:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HANDLER_EXCEPTION_HPP
#define WEBSERV_HANDLER_EXCEPTION_HPP

#include <exception>

namespace webserv
{

namespace handler
{
class Exception : public std::exception
{
	public:
		Exception( void );
		Exception( Exception const& other );
		Exception& operator=( Exception const& other );
		virtual ~Exception() throw();

		Exception( int short status );

		int short status;
};
}  // namespace config

}  // namespace webserv

#endif
