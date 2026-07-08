/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:02:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 10:19:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONFIG_SERVER_HPP
#define WEBSERV_CONFIG_SERVER_HPP

#include "Location.hpp"

namespace webserv
{
namespace config
{

typedef struct
{
		bool							   autoindex;
		size_t							   clientMaxBodySize;
		std::string						   index;
		std::string						   root;
		std::vector< std::string >		   listens;
		std::vector< std::string >		   serverNames;
		std::map< int short, std::string > errorPages;
		std::map< std::string, Location >  locations;
} Server;

}  // namespace config

}  // namespace webserv

#endif
