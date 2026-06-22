/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 19:44:52 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/21 20:57:06 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Client.hpp"

Client::Client( ServerConfig& serverConfig )
: serverConfig( serverConfig )
{}

Client::Client( Client const& other )
: serverConfig( other.serverConfig )
{
	*this = other;
}

Client::~Client()
{}

Client	&Client::operator=( Client const& other )
{
	if ( this != &other )
	{
		status = other.status;
		rawData_ = other.rawData_;
		headersParsed_ = other.headersParsed_;
		serverConfig = other.serverConfig;
	}
	return ( *this );
}

void	Client::read( char const* buffer, int bytesRead )
{
	rawData_.append(buffer, bytesRead);
	if ( !headersParsed_ && ( rawData_.find( "\r\n\r\n" ) != std::string::npos ) )
		parseHeaders();
}

void	Client::parseHeaders( void )
{
	std::stringstream	ss( rawData_.substr( 0, rawData_.find( "\r\n\r\n" ) ) );
	std::string			line;

	while ( std::getline( ss, line ) )
	{
		std::string	key( line.substr(0, line.find(':') ) );
		std::string	value( line.substr(line.find(':'), line.size() ) );
		headers[key] = value;
	}
	headersParsed_ = true;
}
