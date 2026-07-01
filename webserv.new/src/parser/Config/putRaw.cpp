/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putRaw.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:49:25 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 10:49:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::putRaw( std::string const& line ) const
{
	std::string::const_iterator it( line.begin() );

	while ( it != line.end() )
	{
		if ( *it == '#' )
			return;
		if ( *it == '{' || *it == '}' || *it == ';' )
			( *raw_ ) << ' ' << *it << ' ';
		else
			( *raw_ ) << *it;
		it++;
	}
	( *raw_ ) << ' ';
}
