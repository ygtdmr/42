/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:20:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/25 19:51:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <vector>
#include "Tools.hpp"

bool	isValidPath( std::string const& value, bool root )
{
	std::string::const_iterator	it( value.begin() );

	if ( root && ( *value.begin() != '/' ) )
		return ( false );
	if ( value.find("../") != std::string::npos )
		return ( false );
	while ( it != value.end() )
	{
		if ( !( ( *it > 32 ) && ( *it != '\\' ) ) )
			return ( false );
		it++;
	}
	return ( true );
}


bool	isValidDigit( std::string const& value )
{
	std::string::const_iterator	it( value.begin() );

	while ( it != value.end() )
	{
		if ( !( ( *it >= '0' ) && ( *it <= '9' ) ) )
			return ( false );
		it++;
	}
	return ( true );
}

bool	isValidIPv4( std::string const& value )
{
	std::vector<std::string>	octets;
	std::string					currentOctet;
	int							dotCount( 0 );

	for ( size_t i = 0; i < value.length(); ++i )
	{
		if ( value[i] == '.' )
		{
			dotCount++;
			octets.push_back( currentOctet );
			currentOctet = "";
		}
		else
			currentOctet += value[i];
	}
	octets.push_back( currentOctet );

	if ( !( ( dotCount == 3 ) && ( octets.size() == 4 ) ) )
		return ( false );
	for (size_t i = 0; i < octets.size(); ++i)
	{
		if ( octets[i].empty() )
			return ( false );
		if ( ( octets[i].length() > 1 ) && ( *octets[0].begin() == '0' ) )
			return ( false );
		if ( !isValidDigit( octets[i] ) )
			return ( false );
		std::stringstream	ss( octets[i] );
		int					value;

		ss >> value;
		if ( !( value >= 0 && value <= 255 ) )
			return ( false );
	}
	return ( true );
}

std::string strTrim( std::string const& str )
{
	const char	*whitespace( " \t\r\n" );
	size_t		start( str.find_first_not_of(whitespace) );
	size_t		end( str.find_last_not_of( whitespace ) );
	if ( start == std::string::npos )
		return ( "" );
	return ( str.substr( start, end - start + 1 ) );
}

const char	*getReasonPhrase( int statusCode )
{
	switch ( statusCode )
	{
	case 200:
		return ( "OK" );
	case 400:
		return ( "Bad Request" );
	case 404:
		return ( "Not Found" );
	case 413:
		return ( "Content Too Large" );
	case 500:
		return ( "Internal Server Error" );
	case 505:
		return ( "HTTP Version Not Supported" );
	}
	return ( 0 );
}

const char	*getContentType( std::string const& ext )
{
	if ( ext == ".html" || ext == ".htm" )
		return ( "text/html" );
	else if ( ext == ".css" )
		return ( "text/css" );
	else if ( ext == ".js" )
		return ( "application/javascript" );
	else if ( ext == ".txt" )
		return ( "text/plain" );
	else if ( ext == ".jpg" || ext == ".jpeg" )
		return ( "image/jpeg" );
	else if ( ext == ".png" )
		return ( "image/png" );
	else if ( ext == ".gif" )
		return ( "image/gif" );
	else if ( ext == ".bmp" )
		return ( "image/bmp" );
	else if ( ext == ".ico" )
		return ( "image/x-icon" );
	else if ( ext == ".svg" )
		return ( "image/svg+xml" );
	else if ( ext == ".json" )
		return ( "application/json" );
	else if ( ext == ".xml" )
		return ( "application/xml" );
	else if ( ext == ".pdf" )
		return ( "application/pdf" );
	else if ( ext == ".zip" )
		return ( "application/zip" );
	return ( "application/octet-stream" );
}
