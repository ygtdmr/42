/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Headers.hpp"

bool webserv::http::Headers::match( std::string const& key, std::string const& value ) const
{
	if ( !has(key) )
		return false;
	return (*this)[key] == value;
}
