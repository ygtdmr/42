/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:24:03 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Headers.hpp"
#include "utils/str.hpp"
#include <stdexcept>
#include <sstream>

namespace webserv
{
namespace http
{

Headers::Headers( void ) : headers_() {}

Headers::Headers( std::string& str, bool skipFirstLine ) : headers_()
{
	std::stringstream					 ss( str );
	std::string							 line;

	if ( skipFirstLine )
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
			append(key, value);
		}
	}
	if ( !utils::str::skip( str, "\r\n\r\n" ) )
		utils::str::skip( str, "\n\n" );
}

Headers::Headers( Headers const& other )
{
	*this = other;
}

Headers::~Headers() {}

Headers& Headers::operator=( Headers const& other )
{
	if ( this != &other )
		headers_ = other.headers_;
	return *this;
}

std::string& Headers::operator[]( std::string const& key )
{
	std::vector< std::pair<std::string, std::string> >::iterator it(headers_.begin());
	while (it != headers_.end())
	{
		if ( it->first == key )
			return it->second;
		it++;
	}
	throw std::runtime_error("key not found: " + key);
}

const std::string& Headers::operator[]( std::string const& key ) const
{
	std::vector< std::pair<std::string, std::string> >::const_iterator it(headers_.begin());
	while (it != headers_.end())
	{
		if ( it->first == key )
			return it->second;
		it++;
	}
	throw std::runtime_error("key not found: " + key);
}

}  // namespace http

}  // namespace webserv
