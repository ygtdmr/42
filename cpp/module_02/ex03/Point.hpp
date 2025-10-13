/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 15:32:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point( Fixed const &x, Fixed const &y );
	Point( Point const &other );
	~Point();
	Fixed const	&getX( void ) const;
	Fixed const	&getY( void ) const;
private:
	Fixed const	x_;
	Fixed const	y_;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
