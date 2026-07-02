/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:03:08 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 19:27:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/utils/str.hpp"

bool webserv::utils::str::has( std::string const& str, char const* src )
{
	return str.find( src ) != std::string::npos;
}

void webserv::utils::str::skip( std::string& str, char const* src )
{
	str = str.substr( str.find( src ) + std::string( src ).size() );
}
