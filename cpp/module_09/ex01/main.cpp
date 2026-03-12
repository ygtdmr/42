/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:28:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/12 15:58:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "RPN.hpp"

int	main( int argc, char **argv )
{
	try
	{
		if (argc != 2)
			throw std::exception();
		RPN	rpn;
		std::cout
			<< rpn.calc( argv[1] )
			<< std::endl;
	}
	catch( const std::exception& e )
	{
		std::cerr
			<< "Error"
			<< std::endl;
		return ( 1 );
	}
	return ( 0 );
}
