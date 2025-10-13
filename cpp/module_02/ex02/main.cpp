/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 04:57:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 14:26:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}

int	main( void )
{
	{
		std::cout << "----- subject example -----" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		std::cout << "----- basic arithmetic operators -----" << std::endl;
		Fixed a(5.05f);
		Fixed b(2);
		Fixed c = a + b;
		Fixed d = a - b;
		Fixed e = a * b;
		Fixed f = a / b;

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "a + b = " << c << std::endl;
		std::cout << "a - b = " << d << std::endl;
		std::cout << "a * b = " << e << std::endl;
		std::cout << "a / b = " << f << std::endl;

		std::cout << "----- comparison operators -----" << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;

		std::cout << "----- increment / decrement -----" << std::endl;
		Fixed g;
		std::cout << "g = " << g << std::endl;
		std::cout << "++g = " << ++g << std::endl;
		std::cout << "g = " << g << std::endl;
		std::cout << "g++ = " << g++ << std::endl;
		std::cout << "g = " << g << std::endl;
		std::cout << "--g = " << --g << std::endl;
		std::cout << "g = " << g << std::endl;
		std::cout << "g-- = " << g-- << std::endl;
		std::cout << "g = " << g << std::endl;

		std::cout << "----- min / max functions -----" << std::endl;
		Fixed x(1.5f);
		Fixed y(2.25f);
		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
		std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;

		const Fixed cx(10.5f);
		const Fixed cy(42.42f);
		std::cout << "const min(cx, cy) = " << Fixed::min(cx, cy) << std::endl;
		std::cout << "const max(cx, cy) = " << Fixed::max(cx, cy) << std::endl;
	}
	return (0);
}
