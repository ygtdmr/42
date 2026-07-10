/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapToHeaders.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 12:05:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_MAP_TO_HEADERS_HPP
#define WEBSERV_PARSER_MAP_TO_HEADERS_HPP

#include <map>
#include <string>

namespace webserv
{
namespace parser
{
std::string mapToHeaders( std::map< std::string, std::string > const& data );
}  // namespace parser
}  // namespace webserv

#endif
