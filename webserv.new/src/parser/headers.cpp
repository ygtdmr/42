/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:37:15 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 18:08:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/headers.hpp"
#include <exception>
#include <sstream>
#include "../../inc/hpp/utils/str.hpp"

std::map< std::string, std::string > webserv::parser::headers( std::string& data )
{
	std::map< std::string, std::string > headers;
	std::stringstream					 ss( data );
	std::string							 line;

	while ( std::getline( ss, line ) )
	{
		if ( line.empty() )
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
	if ( headers.empty() )
		throw std::exception();
	if ( utils::str::has( data, "\r\n\r\n" ) )
		utils::str::skip( data, "\r\n\r\n" );
	else if ( utils::str::has( data, "\n\n" ) )
		utils::str::skip( data, "\n\n" );
	return headers;
}
