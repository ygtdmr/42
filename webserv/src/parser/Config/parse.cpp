/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:39:11 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include "config/Exception.hpp"
#include "parser/Config.hpp"

void webserv::parser::Config::parse( char const* path )
{
	std::ifstream ifs( path, std::ios::in );
	std::string   line;

	if ( !ifs.is_open() )
		throw config::Exception() << strerror( errno );
	while ( std::getline( ifs, line ) )
		putRaw( line );
	parseStateGlobal();
}
