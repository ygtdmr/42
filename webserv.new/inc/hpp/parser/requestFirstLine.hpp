/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestFirstLine.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:54:12 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 17:54:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_REQUESTFIRSTLINE_HPP
#define WEBSERV_PARSER_REQUESTFIRSTLINE_HPP

#include <map>
#include <string>
#include "../http/Request.hpp"

namespace webserv
{
namespace parser
{
void requestFirstLine( std::string& data, http::Request& request );
}  // namespace parser
}  // namespace webserv

#endif
