/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headersToMap.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/10 18:42:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_HEADERS_TO_MAP_HPP
#define WEBSERV_PARSER_HEADERS_TO_MAP_HPP

#include <map>
#include <string>

namespace webserv
{
namespace parser
{
std::map< std::string, std::string > headersToMap( std::string& data, bool skipFirstLine = true );
}  // namespace parser
}  // namespace webserv

#endif
