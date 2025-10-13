/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:08:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 16:21:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed f)
{
	if (f < Fixed(0))
		f = f * Fixed(-1);
	return (f);
}

static	Fixed calcArea(Point const &a, Point const &b, Point const &c)
{
	Fixed const	s1 = ( a.getX() * ( b.getY() - c.getY() ) );
	Fixed const	s2 = ( b.getX() * ( c.getY() - a.getY() ) );
	Fixed const	s3 = ( c.getX() * ( a.getY() - b.getY() ) );

	return (Fixed(0.5f) * abs(s1 + s2 + s3));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed const	areaABC = calcArea(a, b, c);
	Fixed const	areaABP = calcArea(a, b, point);
	Fixed const	areaACP = calcArea(a, c, point);
	Fixed const	areaBCP = calcArea(b, c, point);

	return
	(
		areaABP > Fixed(0) &&
		areaACP > Fixed(0) &&
		areaBCP > Fixed(0) &&
		(areaABC == (areaABP + areaACP + areaBCP))
	);
}
