/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileExt.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 22:06:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_FILE_EXT_HPP
#define WEBSERV_PARSER_FILE_EXT_HPP

#include <string>

namespace webserv
{
namespace parser
{
char const* fileExt( std::string const& fileName );
}  // namespace parser
}  // namespace webserv

#endif
