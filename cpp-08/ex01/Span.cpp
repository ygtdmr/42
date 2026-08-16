/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:28:51 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 14:43:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include "Span.hpp"

const char	*Span::LimitExceededException::what() const throw()
{
	return ( "Span Exception: maximum capacity reached, cannot add more numbers" );
}

const char	*Span::InsufficientElementsException::what() const throw()
{
	return ( "Span Exception: not enough numbers to calculate a span (minimum 2 required)" );
}

Span::Span()
: numbers_( 0 ), length_( 0 )
{}

Span::Span( unsigned int length )
: numbers_( 0 ), length_ ( length )
{}

Span::Span(const Span &other)
: numbers_( 0 ), length_( 0 )
{
	*this = other;
}

Span	&Span::operator=( const Span &other )
{
	if ( this != &other )
	{
		length_ = other.length_;
		numbers_ = other.numbers_;
	}
	return ( *this );
}

Span::~Span()
{}

void	Span::addNumber( int number )
{
	if ( ( numbers_.size() + 1 ) > length_ )
		throw LimitExceededException();
	numbers_.push_back( number );
}

int	Span::shortestSpan( void )
{
	std::vector<int>	tmp;
	int					result( 0 );

	if ( numbers_.size() < 2 )
		throw InsufficientElementsException();
	tmp = numbers_;
	std::sort( tmp.begin(), tmp.end() );
	for ( size_t i = 0; i < tmp.size() - 1; i++ )
	{
		if ( !i || ( result > ( tmp[i + 1] - tmp[i] ) ) )
			result = ( tmp[i + 1] - tmp[i] );
	}
	return ( result );
}

int	Span::longestSpan( void )
{
	std::vector<int>::iterator	it_min;
	std::vector<int>::iterator	it_max;

	if ( numbers_.size() < 2 )
		throw InsufficientElementsException();
	it_min = std::min_element( numbers_.begin(), numbers_.end() );
	it_max = std::max_element( numbers_.begin(), numbers_.end() );
	return ( *it_max - *it_min );
}
