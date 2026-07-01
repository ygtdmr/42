/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putDataServer.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:48:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 20:09:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"
#include "../../../include/utils/Convertion.tpp"

void webserv::parser::Config::putDataServer( config::Server& server ) const
{
	if ( key_ == "listen" )
	{
		std::string const& value( values_[0] );
		if ( value.find( ':' ) != std::string::npos )
		{
			server.host = value.substr( 0, value.find( ':' ) );
			server.port = value.substr( value.find( ':' ) + 1 );
		}
		else
			server.port = value;
	}
	else if ( key_ == "root" )
		server.root = values_[0];
	else if ( key_ == "server_name" )
		server.serverNames = values_;
	else if ( key_ == "client_max_body_size" )
	{
		char lastChar( *( values_[0].end() - 1 ) );
		bool formatMb( lastChar == 'M' || lastChar == 'm' );
		server.clientMaxBodySize = utils::strTo< size_t >( values_[0] );
		if ( formatMb )
			server.clientMaxBodySize *= 1024 * 1024;
	}
	else if ( key_ == "error_page" )
	{
		std::string								   path( *( values_.end() - 1 ) );
		std::vector< std::string >::const_iterator it( values_.begin() );
		while ( it != values_.end() - 1 )
			server.errorPages[utils::strTo< int short >( *it++ )] = path;
	}
}
