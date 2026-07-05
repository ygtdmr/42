/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerLog.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 18:51:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_SERVER_LOG_TPP
#define WEBSERV_SERVER_LOG_TPP

#include <ctime>
#include <iostream>
#include "../hpp/ServerLog.hpp"
#include "../hpp/utils/conv.hpp"

namespace webserv
{

ServerLog::ServerLog( std::string const& level ) : level_( level ), msg_( "" ) {}

ServerLog::ServerLog( manager::IManager const& manager, std::string const& level ) : level_( level )
{
	manager::Server const* server( dynamic_cast< manager::Server const* >( &manager ) );
	if ( server )
		msg_ = std::string() + "host=[" + server->addr + "], port=[" + server->port + "], ";
	else
		msg_ = std::string() + "addr=[" + manager.addr + "], ";
	msg_ += "fd=[" + utils::conv::toStr< int >( manager.pollfd.fd ) + "], ";
}

template < typename T >
ServerLog& ServerLog::operator<<( T const& any )
{
	std::string str( utils::conv::toStr< T >( any ) );
	if ( str == "\n" )
		printLog();
	else
		msg_ += str;
	return *this;
}

void ServerLog::printLog( void )
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

}  // namespace webserv

#endif
