/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateLocation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:50:12 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:15:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::validateLocation( config::Server const& server,
												std::string const&	  locationPath )
{
	bool valid( false );

	if ( ( key_ == "index" ) && ( values_.size() == 1 ) )
		valid = isValidPath( *values_.begin(), false );
	else if ( ( key_ == "root" || key_ == "cgi_path" || key_ == "upload_dir" ) && ( values_.size() == 1 ) )
		valid = isValidPath( *values_.begin() );
	else if ( ( key_ == "autoindex" ) && ( values_.size() == 1 ) )
		valid = ( *values_.begin() == "on" ) || ( *values_.begin() == "off" );
	else if ( ( key_ == "cgi_extension" ) && ( values_.size() == 1 ) )
		valid = ( *( *values_.begin() ).begin() == '.' ) && ( ( *values_.begin() ).size() > 1 );
	else if ( ( key_ == "return" ) && ( values_.size() == 2 ) )
		valid = ( ( *values_.begin() == "301" || *values_.begin() == "302" ) );
	else if ( ( key_ == "allow_methods" ) && ( values_.size() > 0 ) )
	{
		std::vector< std::string >::const_iterator it( values_.begin() );
		std::vector< std::string >				   validMethods;

		valid = true;
		while ( valid && ( it != values_.end() ) )
		{
			if ( !( *it == "GET" || *it == "POST" || *it == "DELETE" ) )
				valid = false;
			else
			{
				for ( size_t i = 0; valid && ( i < validMethods.size() ); i++ )
					valid = ( *it != validMethods[i] );
				validMethods.push_back( *it );
			}
			it++;
		}
	}
	if ( !valid )
		throw config::Exception( server, locationPath ) << key_ << ": value error";
}
