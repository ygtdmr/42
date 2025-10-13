/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 05:00:08 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 14:38:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	rawBits_ = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->rawBits_ = other.getRawBits();
	return *this;
}

Fixed	Fixed::operator+( const Fixed &other ) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-( const Fixed &other ) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*( const Fixed &other ) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/( const Fixed &other ) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->rawBits_++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp = *this;
	this->rawBits_++;
	return tmp;
}

Fixed	&Fixed::operator--()
{
	this->rawBits_--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp = *this;
	this->rawBits_--;
	return tmp;
}

bool	Fixed::operator>( const Fixed &other ) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<( const Fixed &other ) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=( const Fixed &other ) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=( const Fixed &other ) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==( const Fixed &other ) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=( const Fixed &other ) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed::~Fixed()
{}

Fixed::Fixed( int nbr )
{
	rawBits_ = nbr << fractionalBits_;
}

Fixed::Fixed( float nbr )
{
	rawBits_ = roundf(nbr * (1 << fractionalBits_));
}

int	Fixed::getRawBits( void ) const
{
	return (rawBits_);
}

void	Fixed::setRawBits( int const raw )
{
	rawBits_ = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)rawBits_ / (1 << fractionalBits_));
}

int		Fixed::toInt( void ) const
{
	return (rawBits_ >> fractionalBits_);
}

Fixed	&Fixed::max( Fixed &f1, Fixed &f2 )
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

Fixed	&Fixed::min( Fixed &f1, Fixed &f2 )
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed	&Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}
