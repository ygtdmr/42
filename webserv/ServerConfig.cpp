/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:42:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/14 20:55:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerConfig.hpp"

ServerConfig::ServerConfig( void )
: errorPages( 0 ), locations( 0 )
{}

ServerConfig::ServerConfig( ServerConfig const& other )
{
	*this = other;
}

ServerConfig::~ServerConfig()
{
	if ( errorPages )
		delete errorPages;
	if ( locations )
		delete locations;
}

ServerConfig	&ServerConfig::operator=( ServerConfig const& other )
{
	host = other.host;
	port = other.port;
	clientMaxBodySize = other.clientMaxBodySize;
	if ( errorPages )
		*errorPages = *other.errorPages;
	if ( locations )
		*locations = *other.locations;
	return ( *this );
}
