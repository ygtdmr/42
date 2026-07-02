/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateLocation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:50:12 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 09:18:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::validateLocation( std::string const&	  locationPath ) const
{
	bool valid( false );

	if ( ( key_ == "root" || key_ == "index" || key_ == "upload_dir" ) && ( values_.size() == 1 ) )
		valid = isValidPath( values_[0], key_ != "index" );
	else if ( ( key_ == "autoindex" ) && ( values_.size() == 1 ) )
		valid = ( values_[0] == "on" ) || ( values_[0] == "off" );
	else if ( key_ == "cgi" && ( values_.size() == 2 ) )
	{
		std::string extension( values_[0] );
		std::string path( values_[1] );
		valid = ( *extension.begin() == '.' ) && ( extension.size() > 1 ) && isValidPath( path );
	}
	else if ( ( key_ == "return" ) && ( values_.size() == 2 ) )
		valid = ( ( values_[0] == "301" || values_[0] == "302" ) );
	else if ( ( key_ == "allow_methods" ) && ( values_.size() > 0 ) )
	{
		std::vector< std::string >::const_iterator it( values_.begin() );
		std::vector< std::string >				   validMethods;

		valid = true;
		while ( valid && ( it != values_.end() ) )
		{
			valid = isValidMethod( *it );
			for ( size_t i = 0; valid && ( i < validMethods.size() ); i++ )
				valid = ( *it != validMethods[i] );
			validMethods.push_back( *it );
			it++;
		}
	}
	else if ( ( key_ == "client_max_body_size" ) && ( values_.size() == 1 ) )
	{
		std::string const& value( values_[0] );
		char			   lastChar( *( value.end() - 1 ) );
		bool			   formatMb( lastChar == 'M' || lastChar == 'm' );
		valid = isValidDigit( value.substr( 0, value.size() - formatMb ) );
	}
	if ( !valid )
		throw config::Exception( servers_->size(), locationPath ) << key_ << ": value error";
}
