/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 17:18:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_STR_IPP
#define WEBSERV_UTILS_STR_IPP

#include "../../hpp/utils/str.hpp"

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
	str = str.substr( str.find( src ) );
}

}  // namespace str

}  // namespace utils

}  // namespace webserv

#endif
