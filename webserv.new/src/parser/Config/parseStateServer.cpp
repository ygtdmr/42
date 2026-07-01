/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseStateServer.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:47:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:14:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::parseStateServer( void )
{
	bool		   on_location( false );
	std::string	   word;
	config::Server server;

	while ( ( *raw_ ) >> word )
	{
		if ( on_location )
		{
			if ( word == "{" || word == "}" || word == ";" )
				throw config::Exception( server ) << "invalid location syntax: " << word;
			else
				parseStateLocation( server, word );
			on_location = false;
		}
		else if ( word == "location" )
			on_location = true;
		else if ( word == "}" )
			return servers_->push_back( server );
		else if ( word == ";" )
		{
			validateServer( server );
			putDataServer( server );
			key_ = "";
			values_.clear();
		}
		else if ( key_.empty() )
			key_ = word;
		else
			values_.push_back( word );
	}
}
