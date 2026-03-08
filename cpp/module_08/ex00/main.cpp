/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:41:56 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 11:46:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.tpp"

int	main( void )
{
	// test: std::vector
	std::cout << "--- testing with std::vector ---" << std::endl;
	std::vector<int>	vector;
	for ( int i = 0; i < 5; i++ )
		vector.push_back( i * 10 );

	try
	{
		std::cout << "searching for 30: ";
		std::vector<int>::iterator it(  easyfind( vector, 30 ) );
		std::cout << "success! found value: " << *it << std::endl;

		std::cout << "searching for 99: ";
		easyfind( vector, 99 );
	}
	catch ( const std::exception &e )
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// test: std::list
	std::cout << "\n--- testing with std::list ---" << std::endl;
	std::list<int>	list;
	for ( int i = 0; i < 5; i++ )
		list.push_back( i );

	try
	{
		std::cout << "searching for 4: ";
		std::list<int>::iterator it(  easyfind( list, 4 ) );
		std::cout << "success! found value: " << *it << std::endl;

		std::cout << "searching for 42: ";
		easyfind( list, 42 );
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}

	return	(0);
}
