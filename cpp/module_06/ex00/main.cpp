/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:42:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/27 11:26:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cerr << "Parameter count is invalid." << std::endl;
		return ( 1 );
	}
	else if ( !*argv[1] )
	{
		std::cerr << "Parameter must not be empty." << std::endl;
		return ( 1 );
	}
	ScalarConverter::convert( argv[1] );
	return ( 0 );
}
