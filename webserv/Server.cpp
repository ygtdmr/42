#include "Server.hpp"

Server::Server( std::vector<ServerConfig>& serversConfig )
: serversConfig_( serversConfig )
{}

Server::Server( Server const& other )
: serversConfig_( other.serversConfig_ )
{}

Server::~Server()
{}

Server	&Server::operator=( Server const& other )
{
	if ( this != &other )
		this->serversConfig_ = other.serversConfig_;
	return ( *this );
}

void	Server::setupSockets( void )
{}

void	Server::run( void )
{}
