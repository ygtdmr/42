/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:19:33 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 13:05:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Handler.hpp"

namespace webserv
{
namespace parser
{

Handler::Handler( void ) : handler_( 0 ) {}

Handler::Handler( Handler const& other )
{
	*this = other;
}

Handler::~Handler() {}

Handler& Handler::operator=( Handler const& other )
{
	if ( this != &other )
		handler_ = other.handler_;
	return *this;
}

}  // namespace parser

}  // namespace webserv
