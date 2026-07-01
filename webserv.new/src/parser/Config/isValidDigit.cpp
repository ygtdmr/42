/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidDigit.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:26:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 10:26:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

bool webserv::parser::Config::isValidDigit( std::string const& value ) const
{
	std::string::const_iterator it( value.begin() );

	while ( it != value.end() )
	{
		if ( !( ( *it >= '0' ) && ( *it <= '9' ) ) )
			return false;
		it++;
	}
	return true;
}
