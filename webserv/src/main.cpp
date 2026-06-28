/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:58:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/26 17:44:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/ConfigParser.hpp"
#include "../include/ServerManager.hpp"

int main( int argc, char** argv )
{
	if ( argc != 2 )
	{
		std::cerr << "usage: ./webserv [configuration file]" << std::endl;
		return 1;
	}
	try
	{
		ConfigParser config( argv[1] );
		config.parse();
		ServerManager serverManager;
		serverManager.setupServers( *config.getServers() );
		serverManager.run();
	}
	catch ( std::exception const& e )
	{
		std::cerr << "webserv: " << e.what() << std::endl;
		return 1;
	}
}
