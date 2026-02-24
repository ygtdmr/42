/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:41:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/24 18:02:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <iomanip>
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
	char		*tmp( 0 );
	double	raw( strtod( literal.c_str(), &tmp ) );

	if ( literal.size() == 1 && !(literal[0] >= '0' && literal[0] <= '9') )
	{
		raw = literal[0];
		*tmp = 0;
	}
	print ( literal, (*tmp != 0) && ( std::string("f") !=  tmp ), raw );
}

bool	ScalarConverter::isPseudo( const std::string &literal, char type = 'a' )
{
	const std::string	value( literal.substr((literal[0] == '+') || (literal[0] == '-'), literal.size()) );
	const bool			pseudo( value == "nan" || value == "inf" || value == "inf" );
	const bool			pseudoFloat( value == "nanf" || value == "inff" || value == "inff" );

	switch ( type )
	{
	case 'd':
		return ( pseudo );
	case 'f':
		return ( pseudoFloat );
	case 'a':
	default:
		return ( pseudo || pseudoFloat );
	}
}

void	ScalarConverter::print( const std::string &literal, bool error, const double &raw )
{
	char	c( static_cast<char>( raw ) );
	int		i( static_cast<int>( raw ) );
	float	f( static_cast<float>( raw ) );

	std::cout << "char: ";
	if ( isPseudo(literal) || error )
		std::cout << "impossible";
	else
	{
		if (c >= 32 && i < 127)
			std::cout << c;
		else
			std::cout << "Non displayable";
	}

	std::cout << std::endl << "int: ";
	if ( isPseudo(literal) || error || !( ( raw >= INT_MIN ) && ( raw <= INT_MAX ) ) )
		std::cout << "impossible";
	else
		std::cout << i;

	std::cout << std::endl << "float: ";
	if ( isPseudo( literal ) )
	{
		std::cout << literal;
		if ( isPseudo( literal, 'd' ) )
			std::cout << 'f';
	}
	else if (error || !( ( raw >= FLT_MIN ) && ( raw <= FLT_MAX ) ) )
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << f << 'f';

	std::cout << std::endl << "double: ";
	if ( isPseudo( literal, 'd' ) )
		std::cout << literal;
	else if ( isPseudo( literal, 'f' ) )
		std::cout << literal.substr(0, literal.size() - 1);
	else if (error)
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << raw;

	std::cout << std::endl;
}

