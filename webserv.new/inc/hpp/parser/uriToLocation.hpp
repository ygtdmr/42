/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uriToLocation.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 12:43:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_URI_TO_LOCATION_HPP
#define WEBSERV_PARSER_URI_TO_LOCATION_HPP

#include "../config/Location.hpp"

namespace webserv
{
namespace parser
{
config::Location uriToLocation( std::string const& uri );
}  // namespace parser
}  // namespace webserv

#endif
