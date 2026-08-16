/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 04:57:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/14 12:24:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void	test(Point const &a, Point const &b, Point const &c, Point const &p)
{
	std::cout << "testing point (" << p.getX() << ", " << p.getY() << "): ";
	if (bsp(a, b, c, p))
		std::cout << "inside triangle" << std::endl;
	else
		std::cout << "outside triangle" << std::endl;
}

int main(void)
{
	{
		Point a(0.0f, 0.0f);
		Point b(10.0f, 0.0f);
		Point c(0.0f, 10.0f);

		std::cout << "first triangle (positive coordinates):" << std::endl;
		test(a, b, c, Point(2.0f, 2.0f));
		test(a, b, c, Point(3.5f, 4.2f));
		test(a, b, c, Point(4.999f, 0.001f));
		test(a, b, c, Point(5.0f, 0.0f));
		test(a, b, c, Point(0.0f, 0.0f));
		test(a, b, c, Point(10.0f, 10.0f));
		test(a, b, c, Point(0.1f, 9.9f));
	}
	{
		Point a(-5.0f, -5.0f);
		Point b(5.0f, -5.0f);
		Point c(0.0f, 5.0f);
		std::cout << "second triangle (negative coordinates):" << std::endl;

		test(a, b, c, Point(0.0f, 0.0f)); 
		test(a, b, c, Point(-4.9f, -4.9f));
		test(a, b, c, Point(6.0f, 0.0f));
	}
	return (0);
}

