/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:40:08 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/15 19:17:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <errno.h>
#include <string.h>
#include "ConfigParser.hpp"

ConfigParser::ConfigParser( std::string const& path )
: path_( path ), servers_( 0 )
{}

ConfigParser::ConfigParser( ConfigParser const& other )
{
	*this = other;
}

ConfigParser::~ConfigParser()
{
	if ( servers_ )
		delete servers_;
}

ConfigParser	&ConfigParser::operator=( ConfigParser const& other )
{
	if ( this != &other )
	{
		path_ = other.path_;
		if ( servers_ )
			*servers_ = *other.servers_;
	}
	return ( *this );
}

std::vector<ServerConfig>	*ConfigParser::getServers( void ) const
{
	return ( servers_ );
}

void	ConfigParser::parse( void )
{
	if ( servers_ )
		return ;
	std::ifstream	ifs( this->path_.c_str(), std::ios::in );
	if ( !ifs.is_open() )
		throwError( this->path_ + ": " + strerror(errno) );
	ConfigParserToken *token = getToken( ifs );

	
	std::string	sp;
	while (token)
	{
		std::cout << sp << "words:[";
		for (size_t i = 0; i < token->words.size(); i++)
		{
			std::cout << token->words[i];
			if ( i + 1 < token->words.size() )
				std::cout << "|";
		}

		std::cout << "]";
		if ( token->child )
			std::cout << std::endl << sp << "child:" << std::endl;
		sp += '\t';
		token = token->child;
	}
	

	
}

void	ConfigParser::throwError( std::string const& msg ) const
{
	throw std::runtime_error( "config: " + msg );
}

ConfigParserToken	*ConfigParser::getToken( std::ifstream& ifs ) const
{
	ConfigParserToken	*token( new ConfigParserToken );
	std::string			line;
	std::string			word;

	token->child = 0;
	while ( std::getline( ifs, line ) )
	{
		if ( line.empty() )
			continue ;
		for ( size_t i = 0; i < line.size(); i++ )
		{
			if ( line[i] == '#' )
				break ;
			if ( line[i] == '{' )
			{
				token->child = getToken( ifs );
				break ;
			}
			else if ( line[i] == '}' )
				return ( token );
			else if ( line[i] > 32 && line[i] < 127 )
				word += line[i];
			else if ( !word.empty() )
			{
				token->words.push_back( word );
				word = "";
			}
		}
	}
	return ( token );
}
