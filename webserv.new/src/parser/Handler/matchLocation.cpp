/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matchLocation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:20:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 13:41:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Handler.hpp"

webserv::config::Location const* webserv::parser::Handler::matchLocation(
	std::string const& uri, std::map< std::string, config::Location > const& locations ) const
{
	config::Location const*									  location( 0 );
	std::string												  locationUri;
	std::map< std::string, config::Location >::const_iterator it( locations.begin() );

	while ( it != locations.end() )
	{
		if ( it->first.find( uri ) == 0 )
		{
			if ( !location || ( it->first.size() >= locationUri.size() ) )
			{
				location	= &it->second;
				locationUri = it->first;
			}
		}
		it++;
	}
	return location;
}
