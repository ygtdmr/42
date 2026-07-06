/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extToMimeType.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:58:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 21:59:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_EXT_TO_MIME_TYPE_HPP
#define WEBSERV_PARSER_EXT_TO_MIME_TYPE_HPP

namespace webserv
{
namespace parser
{
char const* extToMimeType( char const* ext );
}  // namespace parser
}  // namespace webserv

#endif
