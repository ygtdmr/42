/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:41:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/28 21:51:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstdlib>
# include <climits>
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
	char		*endptr( 0 );
	bool		error( false );
	double		raw( 0 );

	switch ( type )
	{
	case 'c':
		if ( isdigit( literal[0] ) )
			raw = literal[0] - '0';
		else
			raw = literal[0];
		break;
	case 'i':
	case 'd':
	case 'f':
	case 'p':
		raw = strtod(literal.c_str(), &endptr) ;
		break;
	}
	error = ( type == 'e' || ( endptr && ( *endptr != '\0' && *endptr != 'f' ) ) );
	printChar( raw, error || type == 'p' || !( raw > CHAR_MIN && raw <= CHAR_MAX ) );
	printInt( raw, error || type == 'p' || !( raw >= INT_MIN && raw <= INT_MAX ) );
	printFloat( raw, error );
	printDouble( raw, error );
}

void	ScalarConverter::printErr( void )
{
	std::cout
		<< "impossible";
}

void	ScalarConverter::printChar( const double &raw, const bool &isError )
{
	std::cout
		<< "char: ";
	if ( isError )
		printErr();
	else if ( raw >= 32 )
		std::cout
			<< '\''
			<< static_cast<char>( raw )
			<< '\'';
	else
		std::cout
			<< "Non displayable";
	std::cout
		<< std::endl;
}

void	ScalarConverter::printInt( const double &raw, const bool &isError )
{
	std::cout
		<< "int: ";
	if ( isError )
		printErr();
	else
		std::cout
			<< static_cast<int>( raw );
	std::cout
		<< std::endl;
}

void	ScalarConverter::printFloat( const double &raw, const bool &isError )
{
	std::cout
		<< "float: ";
	if ( isError )
		printErr();
	else
		std::cout
			<< std::fixed
			<< std::setprecision(1)
			<< static_cast<float>( raw )
			<< 'f';
	std::cout
		<< std::endl;
}

void	ScalarConverter::printDouble( const double &raw, const bool &isError )
{
	std::cout
		<< "double: ";
	if ( isError )
		printErr();
	else
		std::cout
			<< std::fixed
			<< std::setprecision(1)
			<< raw;
	std::cout
		<< std::endl;
}

char	ScalarConverter::literalType( const std::string &literal )
{
	const bool	sign( literal[0] == '+' || literal[0] == '-' );
	bool		hasFloat( false );
	int			hasDot( 0 );

	if ( literal.size() == 1 )
		return ( 'c' );
	if ( isPseudo( literal ) )
		return ( 'p' );
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
	else
		return ( 'e' );
}

bool	ScalarConverter::isPseudo( const std::string &literal )
{
	const bool	d( literal == "nan" || literal == "inf" || literal == "-inf" || literal == "+inf" );
	const bool	f( literal == "nanf" || literal == "inff" || literal == "-inff" || literal == "+inff" );

	return ( d || f );
}
