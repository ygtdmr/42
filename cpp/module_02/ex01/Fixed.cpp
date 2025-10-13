/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 05:00:08 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 13:23:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	rawBits_ = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits_ = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( int nbr )
{
	std::cout << "Int constructor called" << std::endl;
	rawBits_ = nbr << fractionalBits_;
}

Fixed::Fixed( float nbr )
{
	std::cout << "Float constructor called" << std::endl;
	rawBits_ = roundf(nbr * (1 << fractionalBits_));
}

int	Fixed::getRawBits( void ) const
{
	return (rawBits_);
}

float	Fixed::toFloat( void ) const
{
	return ((float)rawBits_ / (1 << fractionalBits_));
}

int		Fixed::toInt( void ) const
{
	return (rawBits_ >> fractionalBits_);
}
