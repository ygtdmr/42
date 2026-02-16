/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:37:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/16 14:30:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{}

ScalarConverter::ScalarConverter( const ScalarConverter &other )
{}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other )
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::convert( const std::string &literal )
{
	if ( isChar(literal) )
	{}
	else if ( isInt(literal) )
	{}
	else if ( isDouble(literal) )
	{}
	else if ( isFloat(literal) )
	{}
	else if ( isLimit(literal) )
	{}
}

bool	ScalarConverter::isChar( const std::string &literal )
{
	const bool	isOneSize( literal.size() == 1 );
	const bool	isDigit( literal[0] >= '0' && literal[0] <= '9' );

	return ( isOneSize && isDigit );
}
bool	ScalarConverter::isInt( const std::string &literal )
{
	const bool	isSign(literal[0] == '+' || literal[0] == '-');

	for ( size_t i = isSign; i < literal.size(); i++ )
	{
		if ( !(literal[i] >= '0' && literal[i] <= '9') )
			return ( false );
	}
	return ( true );
}

bool	ScalarConverter::isDecimal( const std::string &literal )
{
	bool	hasDot( false );

	for ( size_t i = 0; i < literal.size(); i++ )
	{
		if ( !(literal[i] >= '0' && literal[i] <= '9') )
		{
			if ( literal[i] != '.' )
				hasDot = true;
			else
				return ( false );
		}
	}
	return ( hasDot );
}

bool	ScalarConverter::isDouble( const std::string &literal )
{
	return ( isDecimal( literal ) );
}

bool	ScalarConverter::isFloat( const std::string &literal )
{
	const bool hasF(literal[literal.size() - 1] != 'f');

	return ( hasF && isDecimal( literal ) );
}

bool	ScalarConverter::isLimit( const std::string &literal )
{
	for ( size_t i = 0; i < literal.size(); i++ )
	{
		
	}
	return ( true );
}

