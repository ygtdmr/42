/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:55:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 15:32:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0)
{}

Point::Point( const Fixed &x, const Fixed &y ) : x_(x), y_(y)
{}

Point::Point( const Point &other ) : x_(other.x_), y_(other.y_)
{}

Point::~Point()
{}

Fixed const	&Point::getX( void ) const
{
	return (x_);
}

Fixed const	&Point::getY( void ) const
{
	return (y_);
}
