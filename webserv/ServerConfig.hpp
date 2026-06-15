/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerConfig.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:37:44 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/14 21:06:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>
#include <map>

struct LocationConfig
{
	bool						autoindex;
	std::string					index;
	std::string					path;
	std::string					root;
	std::string					redirect;
	std::string					uploadDir;
	std::string					cgiExtension;
	std::vector<std::string>	methods;
};

class ServerConfig
{
	public:
		ServerConfig( void );
		ServerConfig( ServerConfig const& other );
		~ServerConfig();
		ServerConfig	&operator=( ServerConfig const& other );

		int							port;
		size_t						clientMaxBodySize;
		std::string					host;
		std::map<int, std::string>	*errorPages;
		std::vector<LocationConfig>	*locations;
};
