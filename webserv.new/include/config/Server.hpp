/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:09:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONFIG_SERVER_HPP
#define WEBSERV_CONFIG_SERVER_HPP

#include <map>
#include "Location.hpp"

namespace webserv
{
namespace config
{

typedef struct
{
		size_t							   clientMaxBodySize;
		std::string						   serverName;
		std::string						   host;
		std::string						   port;
		std::string						   root;
		std::map< int short, std::string > errorPages;
		std::map< std::string, Location >  locations;
} Server;

}  // namespace config

}  // namespace webserv

#endif
