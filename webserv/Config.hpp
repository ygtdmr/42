/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:52:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/24 10:04:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
# define CONFIG_HPP

#include <string>
#include <vector>
#include <map>

struct LocationConfig
{
	bool						autoindex;
	std::string					index;
	std::string					root;
	std::string					uploadDir;
	std::string					cgiExtension;
	std::string					cgiPath;
	std::pair<int, std::string>	redirect;
	std::vector<std::string>	allowMethods;
};

struct ServerConfig
{
	size_t									clientMaxBodySize;
	std::string								host;
	std::string								port;
	std::map<int, std::string>				errorPages;
	std::map<std::string, LocationConfig>	locations;
};

class Config
{
	public:
		Config( std::string const& path );
		Config( Config const& other );
		~Config();
		Config						&operator=( Config const& other );
		std::vector<ServerConfig>	*getServers( void ) const;
		void						parse( void );
	private:
		void						throwError( std::string const& msg ) const;

		void						putRaw( std::string const& line ) const;

		void						parseStateGlobal( void );
		void						parseStateServer( void );
		void						parseStateLocation( ServerConfig& server, std::string const& path );

		void						validateServerConfig( size_t serverIndex );
		void						validateLocationConfig( size_t serverIndex, size_t locationIndex );

		void						putDataServerConfig( ServerConfig& server );
		void						putDataLocationConfig( LocationConfig& location );

		std::string					path_;
		std::string					key_;
		std::vector<std::string>	values_;
		std::stringstream			*raw_;
		std::vector<ServerConfig>	*servers_;
};

#endif
