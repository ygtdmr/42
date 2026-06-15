#include "ConfigParser.hpp"

ConfigParser::ConfigParser( std::string const& path )
: path_( path ), serverConfig_( 0 )
{}

ConfigParser::ConfigParser( ConfigParser const& other )
{
	*this = other;
}

ConfigParser::~ConfigParser()
{
	if ( serverConfig_ )
		delete serverConfig_;
}

ConfigParser	&ConfigParser::operator=( ConfigParser const& other )
{
	if ( this != &other )
	{
		path_ = other.path_;
		if ( serverConfig_ )
			*serverConfig_ =  *other.serverConfig_;
	}
	return ( *this );
}

ServerConfig	*ConfigParser::getServerConfig( void )
{
	return ( serverConfig_ );
}

void	ConfigParser::parse( void )
{
	if ( serverConfig_ )
		return ;
	
}
