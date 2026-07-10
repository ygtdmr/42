/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:30:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 19:37:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_HANDLER_HPP
#define WEBSERV_PARSER_HANDLER_HPP

#include "../manager/Client.hpp"

namespace webserv
{
namespace parser
{
void handler( manager::Client* client );
}  // namespace parser
}  // namespace webserv

#endif
