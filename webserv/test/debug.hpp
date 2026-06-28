#include <iostream>
#include "../include/ServerConfig.hpp"

void printSevers( std::vector<ServerConfig> servers );

std::ostream	&operator<<( std::ostream &os, ServerConfig const &sc );
