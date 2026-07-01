/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateServer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:50:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 20:13:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"
#include "../../../include/utils/Convertion.tpp"

void webserv::parser::Config::validateServer( config::Server const& server ) const
{
	bool valid( false );

	if ( ( key_ == "server_name" ) && ( values_.size() > 0 ) )
	{
		std::vector< std::string >::const_iterator it( values_.begin() );
		valid = true;
		while ( valid && ( it != values_.end() ) )
			valid = isValidServerName( *it++ );
	}
	else if ( ( key_ == "root" ) && ( values_.size() == 1 ) )
		valid = isValidPath( values_[0] );
	else if ( ( key_ == "listen" ) && ( values_.size() == 1 ) )
	{
		std::string const& value( values_[0] );
		if ( value.find( ':' ) != std::string::npos )
		{
			std::string host( value.substr( 0, value.find( ':' ) ) );
			std::string port( value.substr( value.find( ':' ) + 1 ) );
			valid = isValidIPv4( host ) && isValidDigit( port );
		}
		else
			valid = isValidDigit( value );
	}
	else if ( ( key_ == "client_max_body_size" ) && ( values_.size() == 1 ) )
	{
		std::string const& value( values_[0] );
		char			   lastChar( *( value.end() - 1 ) );
		bool			   formatMb( lastChar == 'M' || lastChar == 'm' );
		valid = isValidDigit( value.substr( 0, value.size() - formatMb ) );
	}
	else if ( key_ == "error_page" && ( values_.size() >= 2 ) )
	{
		std::vector< std::string >::const_iterator it( values_.begin() );
		std::vector< int >						   validCodes;
		valid = true;
		while ( valid && ( it != ( values_.end() - 1 ) ) )
		{
			int statusCode( utils::strTo< int short >( *it ) );
			valid = ( statusCode >= 400 && statusCode <= 599 );
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
