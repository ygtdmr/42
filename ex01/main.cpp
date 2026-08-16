/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:28:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 14:46:05 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	std::cout << "--- subject example test ---" << std::endl;
	try
	{
		Span	sp( 5 );
		sp.addNumber( 6 );
		sp.addNumber( 3 );
		sp.addNumber( 17 );
		sp.addNumber( 9 );
		sp.addNumber( 11 );
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--- massive numbers test (15,000 elements) ---" << std::endl;
	try
	{
		Span				bigSpan( 15000 );
		std::vector<int>	randomNums;
		
		srand( time( 0 ) );
		for ( int i = 0; i < 15000; i++ )
			randomNums.push_back( rand() % 1000000 );

		bigSpan.addNumber( randomNums.begin(), randomNums.end() );
		std::cout << "successfully added 15,000 numbers" << std::endl;

		std::cout << "shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "longest span: " << bigSpan.longestSpan() << std::endl;
		
		std::cout << "--- capacity exception test ---" << std::endl;
		std::cout << "trying to add one more number to a full span" << std::endl;
		bigSpan.addNumber( 42 );
		std::cout << "this line should not be printed" << std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}
