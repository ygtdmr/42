/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:21:58 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/Config.hpp"

namespace webserv
{
namespace parser
{

Config::Config( void ) : raw_(), key_(""), values_(), servers_() {}

Config::Config( Config const& other )
{
	*this = other;
}

Config::~Config() {}

Config& Config::operator=( Config const& other )
{
	if ( this != &other )
	{
		key_	= other.key_;
		values_ = other.values_;
		raw_.clear();
		raw_.str( other.raw_.str() );
		servers_ = other.servers_;
	}
	return *this;
}

}  // namespace parser

}  // namespace webserv
