/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:58:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/09 08:33:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_STR_HPP
#define WEBSERV_UTILS_STR_HPP

#include <string>

namespace webserv
{

namespace utils
{

namespace str
{
inline bool		   has( std::string const& str, char const* src );
inline bool		   skip( std::string& str, char const* src );
inline std::string crop( std::string const& str, char const* start, char const* end = 0 );
}  // namespace str

}  // namespace utils

}  // namespace webserv

#include "../../ipp/utils/str.ipp"

#endif
