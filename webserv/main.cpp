/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:58:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/17 16:33:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Config.hpp"
#include "test/debug.hpp"

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
		Config						config(argv[1]);
		std::vector<ServerConfig>	const *serversConfig;

		config.parse();
		serversConfig = config.getServers();
		for (size_t i = 0; i < serversConfig->size(); i++)
			std::cout << (*serversConfig)[i];
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
