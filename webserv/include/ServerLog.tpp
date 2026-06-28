/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerLog.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 18:16:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_LOG_TPP
#define SERVER_LOG_TPP

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "ServerConfig.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

class ServerLog
{
	public:
		ServerLog( std::string const& level ) : level_( level ), msg_( "" ) {}

		ServerLog( ServerConfig const& serverConfig, std::string const& level ) : level_( level )
		{
			std::ostringstream ss;
			std::string		   host( serverConfig.host );
			if ( host.empty() )
				host = "::";
			ss << "host=[" << host << "], port=[" << serverConfig.port << "], ";
			msg_ = ss.str();
		}

		template < typename T >
		ServerLog& operator<<( T const& any )
		{
			std::ostringstream ss;
			ss << any;
			if ( ss.str() == "\n" )
				printLog();
			else
				msg_ += ss.str();
			return *this;
		}

	private:
		void printLog( void )
		{
			char		buffer[80];
			std::time_t rawtime;
			char const* color( "RESET" );

			std::time( &rawtime );
			std::tm* timeinfo( std::localtime( &rawtime ) );
			std::strftime( buffer, sizeof( buffer ), "[%Y-%m-%d %H:%M:%S]", timeinfo );
			if ( level_ == "INFO" )
				color = CYAN;
			else if ( level_ == "ERROR" )
				color = RED;
			else if ( level_ == "SUCCESS" )
				color = GREEN;
			else if ( level_ == "WARNING" )
				color = YELLOW;
			std::cout << color << buffer << " [" << level_ << "] " << msg_ << RESET << std::endl;
			msg_.clear();
			msg_ = "";
		}

		std::string const& level_;
		std::string		   msg_;
};

#endif
