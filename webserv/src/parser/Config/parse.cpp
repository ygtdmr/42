/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:39:11 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:42:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include "../../../inc/hpp/config/Exception.hpp"
#include "../../../inc/hpp/parser/Config.hpp"

void webserv::parser::Config::parse( char const* path )
{
	std::ifstream ifs( path, std::ios::in );
	std::string*  line;

	if ( !ifs.is_open() )
		throw config::Exception() << strerror( errno );
	line = new std::string;
	raw_ = new std::stringstream;
	while ( std::getline( ifs, *line ) )
		putRaw( *line );
	delete line;
	parseStateGlobal();
	delete raw_;
	raw_ = 0;
}
