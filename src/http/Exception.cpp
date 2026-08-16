/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:44:43 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Exception.hpp"

namespace webserv
{
namespace http
{
Exception::Exception( int short status ) : status( status ) {}
Exception::Exception( Exception const& other )
{
	*this = other;
}
Exception& Exception::operator=( Exception const& other )
{
	if ( this != &other )
		status = other.status;
	return *this;
}
Exception::~Exception() throw() {}
}  // namespace http

}  // namespace webserv
