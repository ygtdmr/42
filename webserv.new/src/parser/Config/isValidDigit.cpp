/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidDigit.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:26:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 19:22:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

bool webserv::parser::Config::isValidDigit( std::string const& value ) const
{
	char const* str( "0123456789" );
	return value.find_first_not_of( str ) == std::string::npos;
}
