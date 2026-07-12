/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unchunkBody.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:05:20 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 08:46:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/unchunkBody.hpp"
#include <sstream>

std::string webserv::parser::unchunkBody( std::string& data )
{
	std::string decoded;
	std::size_t pos( 0 );

	while ( pos < data.size() )
	{
		std::size_t nextLineEnd( data.find( "\r\n", pos ) );
		if ( nextLineEnd == std::string::npos )
			break;
		std::string hexSize( data.substr( pos, nextLineEnd - pos ) );

		std::size_t semicolonPos = hexSize.find( ';' );
		if ( semicolonPos != std::string::npos )
			hexSize = hexSize.substr( 0, semicolonPos );

		std::size_t		  chunkSize( 0 );
		std::stringstream ss;
		ss << std::hex << hexSize;
		ss >> chunkSize;

		if ( ss.fail() )
			break;
		if ( chunkSize == 0 )
			break;

		std::size_t payloadStart = nextLineEnd + 2;

		if ( payloadStart + chunkSize + 2 > data.size() )
			break;

		if ( data.substr( payloadStart + chunkSize, 2 ) != "\r\n" )
			break;

		decoded += data.substr( payloadStart, chunkSize );
		pos = payloadStart + chunkSize + 2;
	}
	data = data.substr( pos );
	return decoded;
}
