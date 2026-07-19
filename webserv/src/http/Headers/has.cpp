/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 19:56:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Headers.hpp"

bool webserv::http::Headers::has( std::string const& key ) const
{
	std::vector< std::pair<std::string, std::string> >::const_iterator it(headers_.begin());
	while (it != headers_.end())
	{
		if ( it->first == key )
			return true;
		it++;
	}
	return false;
}
