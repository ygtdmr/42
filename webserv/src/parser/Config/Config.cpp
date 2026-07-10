/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:21:58 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 13:24:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Config.hpp"

namespace webserv
{
namespace parser
{

Config::Config( void ) : raw_( 0 ), servers_( 0 ) {}

Config::Config( Config const& other )
{
	*this = other;
}

Config::~Config()
{
	if ( servers_ )
		delete servers_;
	if ( raw_ )
		delete raw_;
}

Config& Config::operator=( Config const& other )
{
	if ( this != &other )
	{
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

}  // namespace parser

}  // namespace webserv
