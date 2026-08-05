/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:48:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 13:37:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_CONFIG_LOCATION_HPP
#define WEBSERV_CONFIG_LOCATION_HPP

#include <map>
#include <string>
#include <vector>

namespace webserv
{
namespace config
{

typedef struct
{
		bool								 autoindex;
		size_t								 clientMaxBodySize;
		std::string							 uriPath;
		std::string							 index;
		std::string							 root;
		std::string							 uploadDir;
		std::map< std::string, std::string > cgi;
		std::pair< int short, std::string >	 redirect;
		std::vector< std::string >			 allowMethods;
} Location;

}  // namespace config

}  // namespace webserv

#endif
