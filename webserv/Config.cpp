/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 11:40:08 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/18 16:34:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <sstream>
#include <fstream>
#include <errno.h>
#include <string.h>
#include "Config.hpp"

Config::Config( std::string const& path )
: path_( path ), raw_( 0 ), servers_( 0 )
{}

Config::Config( Config const& other )
{
	*this = other;
}

Config::~Config()
{
	if ( servers_ )
		delete servers_;
	if ( raw_ )
		delete raw_;
}

Config	&Config::operator=( Config const& other )
{
	if ( this != &other )
	{
		path_ = other.path_;
		if ( servers_ )
			*servers_ = *(other.servers_);
		if ( raw_ )
		{
			raw_->clear();
			raw_->str( other.raw_->str() );
		}
	}
	return ( *this );
}

std::vector<ServerConfig>	const *Config::getServers( void ) const
{
	return ( servers_ );
}

void	Config::throwError( std::string const& msg ) const
{
	throw std::runtime_error( "config: " + msg );
}

void	Config::parse( void )
{
	std::ifstream	ifs( path_.c_str(), std::ios::in );
	std::string		*line;

	if ( !ifs.is_open() )
		throwError( strerror( errno ) );
	line = new std::string;
	raw_ = new std::stringstream;
	while ( std::getline( ifs, *line ) )
		putRaw( *line );
	delete line;
	parseStateGlobal();
	delete raw_;
	raw_ = 0;
}

void	Config::putRaw( std::string const& line ) const
{	
	std::string::const_iterator	it( line.begin() );

	while ( it != line.end() )
	{
		if ( *it == '#' )
			return ;
		if ( *it == '{' || *it == '}' || *it == ';' )
			( *raw_ ) << ' ' << *it << ' ';
		else
			( *raw_ ) << *it;
		it++;
	}
	( *raw_ ) << ' ';
}

void	Config::parseStateGlobal( void )
{
	bool		on_server( false );
	std::string	word;

	if ( servers_ )
		delete servers_;
	servers_ = new std::vector<ServerConfig>;
	while ( ( *raw_ ) >> word )
	{
		if ( on_server )
		{
			if ( word == "{" )
				parseStateServer();
			else
				throwError( "invalid global syntax: " + word );
			on_server = false;
		}
		else if ( word == "server" )
			on_server = true;
		else
			throwError( "invalid global syntax: " + word );
	}
}

void	Config::parseStateServer( void )
{
	bool			on_location( false );
	std::string		word;
	ServerConfig	server = ServerConfig();

	while ( ( *raw_ ) >> word )
	{
		if ( on_location )
		{
			if ( word == "{" || word == "}" || word == ";" )
				throwError( "invalid location syntax: " + word );
			else
				parseStateLocation( server, word );
			on_location = false;
		}
		else if ( word == "location" )
			on_location = true;
		else if ( word == "}" )
			return ( servers_->push_back( server ) );
		else if ( word == ";" )
		{
			validateServerConfig( servers_->size() );
			putDataServerConfig( server );
			key_ = "";
			values_.clear();
		}
		else if ( key_.empty() )
			key_ = word;
		else
			values_.push_back( word );
	}
}

void	Config::parseStateLocation( ServerConfig& server, std::string const& path )
{
	std::string		word;
	LocationConfig	location = LocationConfig();

	if ( ( ( *raw_ ) >> word ) && ( word != "{" ) )
		throwError( "invalid location syntax: " + word );
	location.path = path;
	while ( ( *raw_ ) >> word )
	{
		if ( word == "}" )
			return( server.locations.push_back( location ) );
		else if ( word == ";" )
		{
			validateLocationConfig( servers_->size(), server.locations.size() );
			putDataLocationConfig( location );
			key_ = "";
			values_.clear();
		}
		else if ( key_.empty() )
			key_ = word;
		else
			values_.push_back( word );
	}
}

void	Config::putDataServerConfig( ServerConfig& server )
{
	std::stringstream	ss( *( values_.begin() ) );

	if ( key_ == "listen" )
		ss >> server.port;
	else if ( key_ == "host" )
		ss >> server.host;
	else if ( key_ == "client_max_body_size" )
		ss >> server.clientMaxBodySize;
	else if ( key_ == "error_page" )
	{
		int											statusCode;
		std::string									path( *( values_.end() - 1 ) );
		std::vector<std::string>::const_iterator	it( values_.begin() );

		while ( it != values_.end() - 1 )
		{
			ss.clear();
			ss.str( *it );
			ss >> statusCode;
			server.errorPages[statusCode] = path;
			it++;
		}
	}
	else
		throwError( "server: invalid key: " + key_ );
}

void	Config::putDataLocationConfig( LocationConfig& location )
{
	std::stringstream	ss( *( values_.begin() ) );

	if ( key_ == "root" )
		ss >> location.root;
	else if ( key_ == "upload_dir" )
		ss >> location.uploadDir;
	else if ( key_ == "cgi_extension" )
		ss >> location.cgiExtension;
	else if ( key_ == "index" )
		ss >> location.index;
	else if ( key_ == "autoindex" )
		location.autoindex = ( ss.str() == "on" );
	else if ( key_ == "allow_methods" )
		location.allowMethods = values_;
	else if ( key_ == "return" )
	{
		ss >> location.redirect.second;
		ss.clear();
		ss.str( *values_.begin() );
		ss >> location.redirect.first;
	}
	else
		throwError( "location: invalid key: " + key_ );
}

void	Config::validateServerConfig( size_t serverIndex )
{
	bool	valid( false );

	if ( ( key_ == "host" ) && ( values_.size() == 1 ) )
		valid = isValidHost( *values_.begin() );
	else if ( ( key_ == "listen" ) && ( values_.size() == 1 ) )
	{
		std::stringstream	ss( *values_.begin() );
		int					port;

		ss >> port;
		valid = isValidDigit( ss.str() ) && ( port >= 1 && port <= 65535 );
	}
	else if ( ( key_ == "client_max_body_size" ) && ( values_.size() == 1 ) )
		valid = isValidDigit( *values_.begin() );
	else if ( key_ == "error_page" && ( values_.size() >= 2 ) )
	{
		std::stringstream							ss;
		std::vector<std::string>::const_iterator	it( values_.begin() );

		while ( it != ( values_.end() - 1 ) )
		{
			int	statusCode;

			ss.clear();
			ss.str( *it );
			ss >> statusCode;
			valid = ( statusCode >= 400 && statusCode <= 511 );
			if ( !valid )
				break ;
			it++;
		}
		valid = valid && isValidPath( *( values_.end() - 1 ) );
	}
	if ( !valid )
	{
		std::stringstream	ss;

		ss << "server(" << serverIndex << "): " << key_ << ": value error";
		throwError( ss.str() );
	}
}

void	Config::validateLocationConfig( size_t serverIndex, size_t locationIndex )
{
	(void) serverIndex;
	(void) locationIndex;
}

bool	Config::isValidDigit( std::string const& value )
{
	std::string::const_iterator	it( value.begin() );

	while ( it != value.end() )
	{
		if ( !(*it >= '0' && *it <= '9') )
			return ( false );
		it++;
	}
	return ( true );
}

bool	Config::isValidHost( std::string const& value )
{
	bool						dot( false );
	std::string::const_iterator	it( value.begin() );

	while ( it != value.end() )
	{
		if ( ( *it == '.' ) && dot )
			return ( false );
		dot = ( *it == '.' );
		if ( !( *it >= '0' && *it <= '9' ) && !dot )
			return ( false );
		it++;
	}
	return ( true );
}

bool	Config::isValidPath( std::string const& value )
{
	std::string::const_iterator	it( value.begin() );

	if ( *value.begin() != '/')
		return ( false );
	if ( value.find("../") != std::string::npos )
		return ( false );
	while ( it != value.end() )
	{
		if ( !( ( *it > 32 ) && ( *it != '\\' ) ) )
			return ( false );
		it++;
	}
	return ( true );
}
