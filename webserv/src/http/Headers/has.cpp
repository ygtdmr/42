/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:30:25 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:30:26 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/Headers.hpp"

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
