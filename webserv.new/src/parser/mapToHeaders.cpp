/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapToHeaders.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 13:43:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 13:50:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/headersToMap.hpp"

std::string mapToHeaders( std::map< std::string, std::string > const& data )
{
	std::map< std::string, std::string >::const_iterator it( data.begin() );
	std::string											 headers;
	while ( it != data.end() )
	{
		headers += it->first + ": " + it->second + "\r\n";
		it++;
	}
	headers += "\r\n";
	return headers;
}
