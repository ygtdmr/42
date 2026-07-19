/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 19:56:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Headers.hpp"

std::string webserv::http::Headers::str( void )
{
	std::string											 			   	str;
	std::vector< std::pair<std::string, std::string> >::const_iterator	it( headers_.begin() );
	while ( it != headers_.end() )
	{
		str += it->first + ": " + it->second + "\r\n";
		it++;
	}
	str += "\r\n";
	return str;
}
