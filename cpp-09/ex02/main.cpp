/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:43:11 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/20 12:35:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "PmergeMe.hpp"

int	main( int argc, char **argv )
{
	try
	{
		PmergeMe	p;
		p.parse( argc, ++argv );
		p.sortAndPrint();
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
