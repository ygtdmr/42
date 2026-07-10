/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headersToMap.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:37:15 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/09 08:34:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/headersToMap.hpp"
#include <exception>
#include <sstream>
#include "../../inc/hpp/utils/str.hpp"

std::map< std::string, std::string > webserv::parser::headersToMap( std::string& data )
{
	std::map< std::string, std::string > headers;
	std::stringstream					 ss( data );
	std::string							 line;

	std::getline( ss, line );
	while ( std::getline( ss, line ) )
	{
		if ( line.empty() || line[0] == '\r' )
			break;
		if ( line.find( ':' ) == std::string::npos )
			throw std::exception();
		std::string key;
		std::string value;
		key = line.substr( 0, line.find( ':' ) );
		if ( key.empty() )
			throw std::exception();
		else
		{
			char const* whitespace( " \t\r\n" );
			value = line.substr( line.find( ':' ) + 1 );
			size_t start( value.find_first_not_of( whitespace ) );
			size_t end( value.find_last_not_of( whitespace ) );
			if ( start != std::string::npos )
				value = value.substr( start, end - start + 1 );
			headers[key] = value;
		}
	}
	if ( !utils::str::skip( data, "\r\n\r\n" ) )
		utils::str::skip( data, "\n\n" );
	return headers;
}
