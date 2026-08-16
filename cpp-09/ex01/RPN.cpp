/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:44:27 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/12 16:31:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <cctype>

RPN::RPN( void )
{}

RPN::RPN( const RPN &other )
{
	*this = other;
}

RPN	&RPN::operator=( const RPN &other )
{
	if ( this != &other )
		numbers_ = other.numbers_;
	return ( *this );
}

RPN::~RPN()
{}

bool	RPN::isOperator( const char &c )
{
	return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

int	RPN::calc( const std::string &input )
{
	int		first;
	int		second;
	int		result;

	for ( size_t i = 0; i < input.size(); i++ )
	{
		if ( std::isspace( input[i] ) )
			continue ;
		if ( std::isdigit( input[i] ) )
			numbers_.push( input[i] - '0' );
		else if( isOperator( input[i] ) )
		{
			if ( numbers_.size() < 2 )
				throw std::exception();
			first = numbers_.top();
			numbers_.pop();
			second = numbers_.top();
			numbers_.pop();
			switch ( input[i] )
			{
			case '+':
				numbers_.push( second + first );
				break;
			case '-':
				numbers_.push( second - first );
				break;
			case '*':
				numbers_.push( second * first );
				break;
			case '/':
				if ( first == 0 )
					throw std::exception();
				numbers_.push( second / first );
				break;
			}
		}
		else
			throw std::exception();
	}
	if ( numbers_.size() != 1 )
		throw std::exception();
	result = numbers_.top();
	numbers_.pop();
	return ( result );
}
