/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 17:13:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_STR_IPP
#define WEBSERV_UTILS_STR_IPP

#include "../../hpp/utils/str.hpp"
#include <iostream>

namespace webserv
{

namespace utils
{

namespace str
{

bool has( std::string const& str, char const* src )
{
	return str.find( src ) != std::string::npos;
}

void skip( std::string& str, char const* src )
{
	str = str.substr( str.find( src ) + std::string(src).size() );
}

std::string crop( std::string const& str, char const* start, char const* end )
{
	if ( !(start && has(str, start)) )
		return "";
	size_t	startPos(str.find(start) + std::string(start).size());
	if ( end )
	{
		size_t	endPos(str.find(end, startPos));
		return str.substr(startPos, endPos - startPos);
	}
	return str.substr(startPos);
}

}  // namespace str

}  // namespace utils

}  // namespace webserv

#endif
