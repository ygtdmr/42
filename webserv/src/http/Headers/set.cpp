/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 20:10:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Headers.hpp"

void webserv::http::Headers::set( std::string const& key, std::string const& value )
{
	if ( has(key) )
		(*this)[key] = value;
	else
		append(key, value);
}
