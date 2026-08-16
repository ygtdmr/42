/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:41:07 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/03 12:44:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement( const T& element )
{
	std::cout << element << ' ';
}

template <typename T>
void incrementElement( T& element )
{
	element++;
}

int main( void )
{
	int A[] = { 1, 2, 3, 4, 5 };
	size_t lenA = 5;

	std::cout << "original array A: ";
	::iter( A, lenA, printElement<int> );
	std::cout << std::endl;

	std::cout << "incrementing array A..." << std::endl;
	::iter( A, lenA, incrementElement<int> );

	std::cout << "modified array A: ";
	::iter( A, lenA, printElement<int>);
	std::cout << std::endl << std::endl;

	std::string B[] = { "Hello", "World" };
	size_t lenB = 2;

	std::cout << "string array B: ";
	::iter( B, lenB, printElement<std::string> );
	std::cout << std::endl;

	return ( 0 );
}
