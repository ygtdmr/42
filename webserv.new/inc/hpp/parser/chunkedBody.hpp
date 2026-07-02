/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkedBody.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 17:10:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_CHUNKEDBODY_HPP
#define WEBSERV_PARSER_CHUNKEDBODY_HPP

#include <string>

namespace webserv
{
namespace parser
{
std::string chunkedBody( std::string const& data );
}  // namespace parser
}  // namespace webserv

#endif
