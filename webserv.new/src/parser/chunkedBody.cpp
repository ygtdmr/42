/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkedBody.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:05:20 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 17:10:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/chunkedBody.hpp"
#include <sstream>

std::string webserv::parser::chunkedBody( std::string const& data )
{
	std::string decoded;
	std::size_t pos( 0 );

	while ( pos < data.size() )
	{
		std::size_t nextLineEnd( data.find( "\r\n", pos ) );
		if ( nextLineEnd == std::string::npos )
			break;
		std::string		  hexSize( data.substr( pos, nextLineEnd - pos ) );
		std::size_t		  chunkSize;
		std::stringstream ss;
		ss << std::hex << hexSize;
		ss >> chunkSize;
		if ( chunkSize == 0 )
			break;
		pos = nextLineEnd + 2;
		if ( pos + chunkSize > data.size() )
			break;
		decoded += data.substr( pos, chunkSize );
		pos += chunkSize + 2;
	}
	return decoded;
}
