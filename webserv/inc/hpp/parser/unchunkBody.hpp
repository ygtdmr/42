/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unchunkBody.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 12:06:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_UNCHUNK_BODY_HPP
#define WEBSERV_PARSER_UNCHUNK_BODY_HPP

#include <string>

namespace webserv
{
namespace parser
{
std::string unchunkBody( std::string& data );
}  // namespace parser
}  // namespace webserv

#endif
