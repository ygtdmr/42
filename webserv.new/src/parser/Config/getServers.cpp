/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getServers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:38:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 11:54:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

std::vector< webserv::config::Server > const* webserv::parser::Config::getServers( void ) const
{
	return servers_;
}