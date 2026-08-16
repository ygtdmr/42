/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidMethod.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 19:19:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/Config.hpp"

bool webserv::parser::Config::isValidMethod( std::string const& value ) const
{
	char const* str( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%&'*+-.^_|~" );
	return value.find_first_not_of( str ) == std::string::npos;
}
