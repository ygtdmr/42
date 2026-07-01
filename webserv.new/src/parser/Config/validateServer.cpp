/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateServer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:50:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:15:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::validateServer( config::Server const& server )
{
	bool valid( false );

	if ( ( key_ == "host" ) && ( values_.size() == 1 ) )
		valid = isValidIPv4( *values_.begin() );
	else if ( ( key_ == "listen" ) && ( values_.size() == 1 ) )
	{
		std::stringstream ss( *values_.begin() );
		int				  port;

		ss >> port;
		valid = isValidDigit( ss.str() ) && ( port >= 1 && port <= 65535 );
	}
	else if ( ( key_ == "client_max_body_size" ) && ( values_.size() == 1 ) )
	{
		std::string& value( *values_.begin() );

		valid = ( *( value.end() - 1 ) == 'M' ) && isValidDigit( value.substr( 0, value.size() - 1 ) );
	}
	else if ( key_ == "error_page" && ( values_.size() >= 2 ) )
	{
		std::stringstream						   ss;
		std::vector< std::string >::const_iterator it( values_.begin() );
		std::vector< int >						   validCodes;

		valid = true;
		while ( valid && ( it != ( values_.end() - 1 ) ) )
		{
			int statusCode;

			ss.clear();
			ss.str( *it );
			ss >> statusCode;
			valid = ( statusCode >= 400 && statusCode <= 511 );
			for ( size_t i = 0; valid && ( i < validCodes.size() ); i++ )
				valid = ( statusCode != validCodes[i] );
			validCodes.push_back( statusCode );
			it++;
		}
		valid = valid && isValidPath( *( values_.end() - 1 ) );
	}
	if ( !valid )
		throw config::Exception( server ) << key_ << ": value error";
}
