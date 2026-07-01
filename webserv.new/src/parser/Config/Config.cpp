/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:21:58 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 10:37:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

webserv::parser::Config::Config( std::string const& path ) : path_( path ), raw_( 0 ), servers_( 0 ) {}

webserv::parser::Config::Config( Config const& other )
{
	*this = other;
}

webserv::parser::Config::~Config()
{
	if ( servers_ )
		delete servers_;
	if ( raw_ )
		delete raw_;
}

webserv::parser::Config& webserv::parser::Config::operator=( Config const& other )
{
	if ( this != &other )
	{
		path_	= other.path_;
		key_	= other.key_;
		values_ = other.values_;
		if ( raw_ )
		{
			raw_->clear();
			raw_->str( other.raw_->str() );
		}
		if ( servers_ )
			*servers_ = *other.servers_;
	}
	return *this;
}
