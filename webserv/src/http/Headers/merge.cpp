/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 19:56:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Headers.hpp"

void webserv::http::Headers::merge( Headers const& other )
{
	std::vector< std::pair<std::string, std::string> >::const_iterator it(other.headers_.begin());
	while (it != other.headers_.end())
	{
		append(it->first, it->second);
		it++;
	}
}
