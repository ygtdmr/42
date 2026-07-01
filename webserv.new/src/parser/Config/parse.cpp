/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:39:11 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:13:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fstream>
#include "../../../include/config/Exception.tpp"
#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::parse( void )
{
	std::ifstream ifs( path_.c_str(), std::ios::in );
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
