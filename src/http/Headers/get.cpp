/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:30:06 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:30:06 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Headers.hpp"

std::string webserv::http::Headers::get( std::string const& key ) const
{
	if ( has(key) )
		return (*this)[key];
	return "";
}
