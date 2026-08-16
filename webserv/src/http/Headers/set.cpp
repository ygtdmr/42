/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:31:34 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:31:35 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/Headers.hpp"

void webserv::http::Headers::set( std::string const& key, std::string const& value )
{
	if ( has(key) )
		(*this)[key] = value;
	else
		append(key, value);
}
