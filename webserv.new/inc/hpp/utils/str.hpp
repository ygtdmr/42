/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:58:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 19:27:11 by yidemir          ###   ########.fr       */
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
bool has( std::string const& str, char const* src );
void skip( std::string& str, char const* src );
}  // namespace str

}  // namespace utils

}  // namespace webserv

#endif
