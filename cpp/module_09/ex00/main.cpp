/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:28:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/10 17:28:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	try
	{
		BitcoinExchange	btc_exc;

		if ( argc != 2 )
			throw BitcoinExchange::Error( BitcoinExchange::Error::FILE_COULD_NOT_OPEN );
		btc_exc.parseInput( argv[1] );
	}
	catch( const std::exception& e )
	{
		std::cerr << e.what() << std::endl;
		return ( 1 );
	}
	return ( 0 );
}
