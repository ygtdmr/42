/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:31:26 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:31:26 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/Headers.hpp"

void webserv::http::Headers::merge( Headers const& other )
{
	std::vector< std::pair<std::string, std::string> >::const_iterator it(other.headers_.begin());
	while (it != other.headers_.end())
	{
		append(it->first, it->second);
		it++;
	}
}
