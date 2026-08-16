/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:39:11 by yidemir           #+#    #+#             */
/*   Updated: 2026/08/05 17:07:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include "config/Exception.hpp"
#include "parser/Config.hpp"

void webserv::parser::Config::parse( char const* path )
{
	struct stat st;
	std::ifstream ifs( path, std::ios::in );
	std::string   line;

	if ( !ifs.is_open() )
		throw config::Exception() << strerror( errno );
	stat( path, &st );
	if ( S_ISDIR( st.st_mode ) )
		throw config::Exception() << "Path should be file.";
	while ( std::getline( ifs, line ) )
		putRaw( line );
	parseStateGlobal();
}
