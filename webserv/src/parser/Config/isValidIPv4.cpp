/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidIPv4.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:23:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 18:10:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Config.hpp"
#include "../../../inc/hpp/utils/conv.hpp"

bool webserv::parser::Config::isValidIPv4( std::string const& value ) const
{
	std::vector< std::string > octets;
	std::string				   currentOctet;
	int						   dotCount( 0 );

	for ( size_t i = 0; i < value.length(); ++i )
	{
		if ( value[i] == '.' )
		{
			dotCount++;
			octets.push_back( currentOctet );
			currentOctet = "";
		}
		else
			currentOctet += value[i];
	}
	octets.push_back( currentOctet );

	if ( !( ( dotCount == 3 ) && ( octets.size() == 4 ) ) )
		return false;
	for ( size_t i = 0; i < octets.size(); ++i )
	{
		if ( octets[i].empty() )
			return false;
		if ( ( octets[i].length() > 1 ) && ( *octets[0].begin() == '0' ) )
			return false;
		if ( !isValidDigit( octets[i] ) )
			return false;

		int value( utils::conv::strTo< int >( octets[i] ) );

		if ( !( value >= 0 && value <= 255 ) )
			return false;
	}
	return true;
}
