/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimeTypeToExt.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:52:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 12:58:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_MIME_TYPE_TO_EXT_HPP
#define WEBSERV_PARSER_MIME_TYPE_TO_EXT_HPP

#include <string>

namespace webserv
{
namespace parser
{
char const* mimeTypeToExt( std::string const& mimeType );
}  // namespace parser
}  // namespace webserv

#endif
