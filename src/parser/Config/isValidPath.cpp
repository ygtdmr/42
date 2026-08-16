/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidPath.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:26:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/08/05 18:47:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/Config.hpp"

bool webserv::parser::Config::isValidPath( std::string const& value, bool root ) const
{
	std::string::const_iterator it( value.begin() );

	if ( root && ( *value.begin() != '/' ) )
		return false;
	while ( it != value.end() )
	{
		if ( !( ( *it > 32 ) && ( *it != '\\' ) ) )
			return false;
		it++;
	}
	return true;
}
