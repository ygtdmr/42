/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:58:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/19 19:52:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Config.hpp"
#include "Server.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout
			<< "usage: ./webserv [configuration file]"
			<< std::endl;
		return ( 1 );
	}
	try
	{
		Config	config( argv[1] );
		config.parse();

		Server	server( *config.getServers() );
		server.setup();
		server.run();
	}
	catch( const std::exception& e )
	{
		std::cerr
			<< "webserv: " << e.what()
			<< std::endl;
		return (1);
	}
}
