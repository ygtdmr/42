/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:31:39 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:31:40 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/Headers.hpp"

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
