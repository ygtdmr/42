/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Log.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:34:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/13 19:37:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_LOG_TPP
#define WEBSERV_HTTP_LOG_TPP

#include <ctime>
#include <iostream>
#include "../hpp/http/Log.hpp"
#include "../hpp/utils/conv.hpp"

namespace webserv
{

namespace http
{

Log::Log( std::string const& level ) : level_( level ), msg_( "" ) {}

Log::Log( http::Server const& server, std::string const& level )
	: level_( level )
	, msg_( "host=[" + server.addr + "], port=[" + server.port + "], fd=[" +
			utils::conv::toStr< int >( server.fd ) + "], " )
{}

Log::Log( http::Client const& client, std::string const& level )
	: level_( level )
	, msg_( "addr=[" + client.addr + "], fd=[" + utils::conv::toStr< int >( client.fd ) + "], " )
{}

template < typename T >
Log& Log::operator<<( T const& any )
{
	std::string str( utils::conv::toStr< T >( any ) );
	if ( str == "\n" )
		printLog();
	else
		msg_ += str;
	return *this;
}

void Log::printLog( void )
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

}  // namespace http

}  // namespace webserv

#endif
