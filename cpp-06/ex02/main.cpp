/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:42:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/02 16:37:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate( void )
{
	int	result(rand() % 3);

	switch ( result )
	{
	case 0:
		return ( new A() );
	case 1:
		return ( new B() );
	case 2:
		return ( new C() );
	}
	return ( 0 );
}

void	identify( Base *p )
{
	if ( dynamic_cast<A*>(p) != 0 )
		std::cout << "class type is: A";
	else if ( dynamic_cast<B*>(p) != 0 )
		std::cout << "class type is: B";
	else if ( dynamic_cast<C*>(p) != 0 )
		std::cout << "class type is: C";
	std::cout << std::endl;
}

void	identify( Base &p )
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "class type is: A" << std::endl;
		return ;
	}
	catch( const std::exception &e )
	{}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "class type is: B" << std::endl;
		return ;
	}
	catch( const std::exception &e )
	{}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "class type is: C" << std::endl;
		return ;
	}
	catch( const std::exception &e )
	{}
}

int	main( void )
{
	A	a;
	B	b;
	C	c;

	srand( static_cast<unsigned int>( time( 0 ) ) );
	std::cout << "--------------------" << std::endl;
	std::cout << "pointer identify test" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		Base	*b( generate() );
		identify( b );
		delete b;
	}
	std::cout << "--------------------" << std::endl;
	std::cout << "reference test" << std::endl;
	std::cout << "--------------------" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	return ( 0 );
}
