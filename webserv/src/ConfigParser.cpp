/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConfigParser.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:21:58 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/27 18:47:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ConfigParser.hpp"
#include <errno.h>
#include <string.h>
#include <fstream>
#include "../include/ConfigException.tpp"

ConfigParser::ConfigParser( std::string const& path ) : path_( path ), raw_( 0 ), servers_( 0 ) {}

ConfigParser::ConfigParser( ConfigParser const& other )
{
	*this = other;
}

ConfigParser::~ConfigParser()
{
	if ( servers_ )
		delete servers_;
	if ( raw_ )
		delete raw_;
}

ConfigParser& ConfigParser::operator=( ConfigParser const& other )
{
	if ( this != &other )
	{
		path_	= other.path_;
		key_	= other.key_;
		values_ = other.values_;
		if ( raw_ )
		{
			raw_->clear();
			raw_->str( other.raw_->str() );
		}
		if ( servers_ )
			*servers_ = *other.servers_;
	}
	return *this;
}

std::vector< ServerConfig > const* ConfigParser::getServers( void ) const
{
	return servers_;
}

void ConfigParser::parse( void )
{
	std::ifstream ifs( path_.c_str(), std::ios::in );
	std::string*  line;

	if ( !ifs.is_open() )
		throw ConfigException() << strerror( errno );
	line = new std::string;
	raw_ = new std::stringstream;
	while ( std::getline( ifs, *line ) )
		putRaw( *line );
	delete line;
	parseStateGlobal();
	delete raw_;
	raw_ = 0;
}

void ConfigParser::putRaw( std::string const& line ) const
{
	std::string::const_iterator it( line.begin() );

	while ( it != line.end() )
	{
		if ( *it == '#' )
			return;
		if ( *it == '{' || *it == '}' || *it == ';' )
			( *raw_ ) << ' ' << *it << ' ';
		else
			( *raw_ ) << *it;
		it++;
	}
	( *raw_ ) << ' ';
}

void ConfigParser::parseStateGlobal( void )
{
	bool		on_server( false );
	std::string word;

	if ( servers_ )
		delete servers_;
	servers_ = new std::vector< ServerConfig >;
	while ( ( *raw_ ) >> word )
	{
		if ( on_server )
		{
			if ( word == "{" )
				parseStateServer();
			else
				throw ConfigException() << "invalid global syntax: " << word;
			on_server = false;
		}
		else if ( word == "server" )
			on_server = true;
		else
			throw ConfigException() << "invalid global syntax: " << word;
	}
}

void ConfigParser::parseStateServer( void )
{
	bool		 on_location( false );
	std::string	 word;
	ServerConfig serverConfig;

	while ( ( *raw_ ) >> word )
	{
		if ( on_location )
		{
			if ( word == "{" || word == "}" || word == ";" )
				throw ConfigException( serverConfig ) << "invalid location syntax: " << word;
			else
				parseStateLocation( serverConfig, word );
			on_location = false;
		}
		else if ( word == "location" )
			on_location = true;
		else if ( word == "}" )
			return servers_->push_back( serverConfig );
		else if ( word == ";" )
		{
			validateServerConfig( serverConfig );
			putDataServerConfig( serverConfig );
			key_ = "";
			values_.clear();
		}
		else if ( key_.empty() )
			key_ = word;
		else
			values_.push_back( word );
	}
}

void ConfigParser::parseStateLocation( ServerConfig& serverConfig, std::string const& path )
{
	std::string	   word;
	LocationConfig location = LocationConfig();

	if ( ( ( *raw_ ) >> word ) && ( word != "{" ) )
		throw ConfigException( serverConfig, path ) << "invalid location syntax: " << word;
	else if ( !isValidPath( path ) )
		throw ConfigException( serverConfig, path ) << "invalid location path: " << word;
	while ( ( *raw_ ) >> word )
	{
		if ( word == "}" )
		{
			if ( serverConfig.locations.find( path ) == serverConfig.locations.end() )
				serverConfig.locations.insert( std::make_pair( path, location ) );
			else
				throw ConfigException( serverConfig, path ) << "duplicate location: " << path;
			return;
		}
		else if ( word == ";" )
		{
			validateLocationConfig( serverConfig, path );
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

void ConfigParser::validateServerConfig( ServerConfig const& serverConfig )
{
	bool valid( false );

	if ( ( key_ == "host" ) && ( values_.size() == 1 ) )
		valid = isValidIPv4( *values_.begin() );
	else if ( ( key_ == "listen" ) && ( values_.size() == 1 ) )
	{
		std::stringstream ss( *values_.begin() );
		int				  port;

		ss >> port;
		valid = isValidDigit( ss.str() ) && ( port >= 1 && port <= 65535 );
	}
	else if ( ( key_ == "client_max_body_size" ) && ( values_.size() == 1 ) )
	{
		std::string& value( *values_.begin() );

		valid = ( *( value.end() - 1 ) == 'M' ) && isValidDigit( value.substr( 0, value.size() - 1 ) );
	}
	else if ( key_ == "error_page" && ( values_.size() >= 2 ) )
	{
		std::stringstream						   ss;
		std::vector< std::string >::const_iterator it( values_.begin() );
		std::vector< int >						   validCodes;

		valid = true;
		while ( valid && ( it != ( values_.end() - 1 ) ) )
		{
			int statusCode;

			ss.clear();
			ss.str( *it );
			ss >> statusCode;
			valid = ( statusCode >= 400 && statusCode <= 511 );
			for ( size_t i = 0; valid && ( i < validCodes.size() ); i++ )
				valid = ( statusCode != validCodes[i] );
			validCodes.push_back( statusCode );
			it++;
		}
		valid = valid && isValidPath( *( values_.end() - 1 ) );
	}
	if ( !valid )
		throw ConfigException( serverConfig ) << key_ << ": value error";
}

void ConfigParser::validateLocationConfig( ServerConfig const& serverConfig, std::string const& locationPath )
{
	bool valid( false );

	if ( ( key_ == "index" ) && ( values_.size() == 1 ) )
		valid = isValidPath( *values_.begin(), false );
	else if ( ( key_ == "root" || key_ == "cgi_path" || key_ == "upload_dir" ) && ( values_.size() == 1 ) )
		valid = isValidPath( *values_.begin() );
	else if ( ( key_ == "autoindex" ) && ( values_.size() == 1 ) )
		valid = ( *values_.begin() == "on" ) || ( *values_.begin() == "off" );
	else if ( ( key_ == "cgi_extension" ) && ( values_.size() == 1 ) )
		valid = ( *( *values_.begin() ).begin() == '.' ) && ( ( *values_.begin() ).size() > 1 );
	else if ( ( key_ == "return" ) && ( values_.size() == 2 ) )
		valid = ( ( *values_.begin() == "301" || *values_.begin() == "302" ) );
	else if ( ( key_ == "allow_methods" ) && ( values_.size() > 0 ) )
	{
		std::vector< std::string >::const_iterator it( values_.begin() );
		std::vector< std::string >				   validMethods;

		valid = true;
		while ( valid && ( it != values_.end() ) )
		{
			if ( !( *it == "GET" || *it == "POST" || *it == "DELETE" ) )
				valid = false;
			else
			{
				for ( size_t i = 0; valid && ( i < validMethods.size() ); i++ )
					valid = ( *it != validMethods[i] );
				validMethods.push_back( *it );
			}
			it++;
		}
	}
	if ( !valid )
		throw ConfigException( serverConfig, locationPath ) << key_ << ": value error";
}

void ConfigParser::putDataServerConfig( ServerConfig& serverConfig )
{
	std::stringstream ss( *( values_.begin() ) );

	if ( key_ == "listen" )
		ss >> serverConfig.port;
	else if ( key_ == "host" )
		ss >> serverConfig.host;
	else if ( key_ == "client_max_body_size" )
	{
		ss >> serverConfig.clientMaxBodySize;
		serverConfig.clientMaxBodySize *= 1024 * 1024;
	}
	else if ( key_ == "error_page" )
	{
		int										   statusCode;
		std::string								   path( *( values_.end() - 1 ) );
		std::vector< std::string >::const_iterator it( values_.begin() );

		while ( it != values_.end() - 1 )
		{
			ss.clear();
			ss.str( *it );
			ss >> statusCode;
			serverConfig.errorPages[statusCode] = path;
			it++;
		}
	}
}

void ConfigParser::putDataLocationConfig( LocationConfig& location )
{
	std::stringstream ss( *( values_.begin() ) );

	if ( key_ == "root" )
		ss >> location.root;
	else if ( key_ == "upload_dir" )
		ss >> location.uploadDir;
	else if ( key_ == "cgi_extension" )
		ss >> location.cgiExtension;
	else if ( key_ == "cgi_path" )
		ss >> location.cgiPath;
	else if ( key_ == "index" )
		ss >> location.index;
	else if ( key_ == "autoindex" )
		location.autoindex = ( ss.str() == "on" );
	else if ( key_ == "allow_methods" )
		location.allowMethods = values_;
	else if ( key_ == "return" )
	{
		ss >> location.redirect.first;
		ss.clear();
		ss.str( *( values_.end() - 1 ) );
		ss >> location.redirect.second;
	}
}

bool ConfigParser::isValidPath( std::string const& value, bool root )
{
	std::string::const_iterator it( value.begin() );

	if ( root && ( *value.begin() != '/' ) )
		return false;
	if ( value.find( "../" ) != std::string::npos )
		return false;
	while ( it != value.end() )
	{
		if ( !( ( *it > 32 ) && ( *it != '\\' ) ) )
			return false;
		it++;
	}
	return true;
}

bool ConfigParser::isValidDigit( std::string const& value )
{
	std::string::const_iterator it( value.begin() );

	while ( it != value.end() )
	{
		if ( !( ( *it >= '0' ) && ( *it <= '9' ) ) )
			return false;
		it++;
	}
	return true;
}

bool ConfigParser::isValidIPv4( std::string const& value )
{
	std::vector< std::string > octets;
	std::string				   currentOctet;
	int						   dotCount( 0 );

	for ( size_t i = 0; i < value.length(); ++i )
	{
		if ( value[i] == '.' )
		{
			dotCount++;
			octets.push_back( currentOctet );
			currentOctet = "";
		}
		else
			currentOctet += value[i];
	}
	octets.push_back( currentOctet );

	if ( !( ( dotCount == 3 ) && ( octets.size() == 4 ) ) )
		return false;
	for ( size_t i = 0; i < octets.size(); ++i )
	{
		if ( octets[i].empty() )
			return false;
		if ( ( octets[i].length() > 1 ) && ( *octets[0].begin() == '0' ) )
			return false;
		if ( !isValidDigit( octets[i] ) )
			return false;
		std::stringstream ss( octets[i] );
		int				  value;

		ss >> value;
		if ( !( value >= 0 && value <= 255 ) )
			return false;
	}
	return true;
}
