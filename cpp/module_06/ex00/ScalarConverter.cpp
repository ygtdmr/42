/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:41:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/27 12:11:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iomanip>
# include <iostream>
# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{}

ScalarConverter::ScalarConverter( const ScalarConverter &other )
{
	( void ) other;
}

ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other )
{
	( void ) other;
	return ( *this );
}

ScalarConverter::~ScalarConverter()
{}

void	ScalarConverter::convert( const std::string &literal )
{
	const char	type( literalType( literal ) );
	char		*endptr;
	double		raw;

	switch ( type )
	{
	case 'c':
		raw = literal[0];
		break;
	case 'i':
		raw = strtod( literal.c_str(), &endptr );
		break;
	case 'f':
		raw = strtof(literal.c_str(), &endptr );
		break;
	case 'd':
		raw = strtod(literal.c_str(), &endptr) ;
		break;
	}
	print( static_cast<char>( raw ), type == 'e' );
	print( static_cast<int>( raw ), type == 'e' || !( raw >= INT_MIN && raw <= INT_MAX ) );
	print( static_cast<float>( raw ), type == 'e' || *endptr, literal );
	print( static_cast<double>( raw ), type == 'e' || *endptr, literal );
}

void	ScalarConverter::printErr( void )
{
	std::cout
		<< "impossible";
}

void	ScalarConverter::print( const char &value, const bool isError )
{
	std::cout
		<< "char: ";
	if ( isError )
		printErr();
	else if ( value >= 32 )
		std::cout
			<< '\''
			<< value
			<< '\'';
	else
		std::cout
			<< "Non displayable";
	std::cout
		<< std::endl;
}

void	ScalarConverter::print( const int &value, const bool isError )
{
	std::cout
		<< "int: ";
	if ( isError )
		printErr();
	else
		std::cout
			<< value;
	std::cout
		<< std::endl;
}

void	ScalarConverter::print( const float &value, const bool isError, const std::string &literal )
{
	std::cout
		<< "float: ";
	if ( isError )
		printErr();
	else
	{
		if ( isPseudoFloat ( literal ) )
			std::cout
				<< literal;
		else if ( isPseudoDouble( literal ) )
			std::cout
				<< literal
				<< 'f';
		else
			std::cout
				<< std::fixed
				<< std::setprecision(1)
				<< value;
	}
	std::cout
		<< std::endl;
}

void	ScalarConverter::print( const double &value, const bool isError, const std::string &literal )
{
	std::cout
		<< "double: ";
	if ( isError )
		printErr();
	else
	{
		if ( isPseudoFloat ( literal ) )
			std::cout
				<< literal.substr( 0, literal.size() - 1 );
		else if ( isPseudoDouble( literal ) )
			std::cout
				<< literal;
		else
			std::cout
				<< std::fixed
				<< std::setprecision(1)
				<< value;
	}
	std::cout
		<< std::endl;
}

char	ScalarConverter::literalType( const std::string &literal )
{
	if ( literal.size() == 1 )
		return ( 'c' );
	else
	{
		const bool	sign( literal[0] == '+' || literal[0] == '-' );
		bool		hasFloat( false );
		int			hasDot( 0 );

		for (size_t i = sign; i < literal.size(); i++)
		{
			if ( literal[i] == '.' && ( i && isdigit( literal[i + 1] ) ) )
				hasDot ++;
			else if ( literal[i] == 'f' && isdigit( literal[i - 1] ) )
				hasFloat = true;
			else if ( !isdigit( literal[i] ) )
				return ( 'e' );
		}
		if ( hasFloat && (hasDot == 1 || !hasDot) )
			return ( 'f' );
		else if ( hasDot == 1 )
			return ( 'd' );
		else if ( !hasDot )
			return ( 'i' );
		return ( 'e' );
	}
}

bool	ScalarConverter::isPseudoDouble( const std::string &literal )
{
	return ( literal == "nan" || literal == "inf" || literal == "-inf" || literal == "+inf" );
}

bool	ScalarConverter::isPseudoFloat( const std::string &literal )
{
	return ( literal == "nanf" || literal == "inff" || literal == "-inff" || literal == "+inff" );
}
