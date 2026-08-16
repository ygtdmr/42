/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseStateGlobal.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:45:39 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config/Exception.hpp"
#include "parser/Config.hpp"

void webserv::parser::Config::parseStateGlobal( void )
{
	bool		on_server( false );
	std::string word;

	servers_ = std::vector< config::Server >();
	while ( raw_  >> word )
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
