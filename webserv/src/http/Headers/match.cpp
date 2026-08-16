/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:31:03 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:31:04 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/Headers.hpp"

bool webserv::http::Headers::match( std::string const& key, std::string const& value ) const
{
	if ( !has(key) )
		return false;
	return (*this)[key] == value;
}
