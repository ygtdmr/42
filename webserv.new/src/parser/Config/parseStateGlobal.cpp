/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseStateGlobal.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:45:39 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:46:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/config/Exception.hpp"
#include "../../../inc/hpp/parser/Config.hpp"

void webserv::parser::Config::parseStateGlobal( void )
{
	bool		on_server( false );
	std::string word;

	if ( servers_ )
		delete servers_;
	servers_ = new std::vector< config::Server >;
	while ( ( *raw_ ) >> word )
	{
		if ( on_server )
		{
			if ( word == "{" )
				parseStateServer();
			else
				throw config::Exception() << "invalid global syntax: " << word;
			on_server = false;
		}
		else if ( word == "server" )
			on_server = true;
		else
			throw config::Exception() << "invalid global syntax: " << word;
	}
}
