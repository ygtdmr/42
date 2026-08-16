/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 18:14:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HANDLER_EXCEPTION_HPP
#define WEBSERV_HANDLER_EXCEPTION_HPP

#include <exception>

namespace webserv
{

namespace http
{

class Exception : public std::exception
{
	public:
		Exception( int short status );
		Exception( Exception const& other );
		Exception& operator=( Exception const& other );
		virtual ~Exception() throw();

		int short status;
};

}  // namespace http

}  // namespace webserv

#endif
