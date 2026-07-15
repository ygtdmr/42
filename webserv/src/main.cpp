/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:58:59 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 15:27:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/hpp/Controller.hpp"
#include "../inc/hpp/parser/Config.hpp"

int main( int argc, char** argv )
{
	if ( argc != 2 )
	{
		std::cerr << "usage: ./webserv [configuration file]" << std::endl;
		return 1;
	}
	try
	{
		webserv::parser::Config config;
		config.parse( argv[1] );
		webserv::Controller controller;
		controller.setup( config.getServers() );
		controller.run();
	}
	catch ( std::exception const& e )
	{
		std::cerr << "webserv: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
