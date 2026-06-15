/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:58:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/15 14:13:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ConfigParser.hpp"

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
		ConfigParser	configParser(argv[1]);
		std::vector<ServerConfig>	*configServers;

		configParser.parse();
		configServers = configParser.getServers();
	}
	catch( const std::exception& e )
	{
		std::cerr
			<< "webserv: "
			<< e.what()
			<< std::endl;
		return (1);
	}
}
