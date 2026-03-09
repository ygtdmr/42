/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:08 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/09 21:55:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::Error::Error( TYPE type )
: type_( type )
{}

const char	*BitcoinExchange::Error::what() const throw()
{
	switch ( type_ )
	{
	case FILE_COULD_NOT_OPEN:
		return ( "Error: could not open file." );
	case FILE_CSV_COULD_NOT_OPEN:
		return ( "Error: could not open csv file." );
	case FILE_CSV_COULD_NOT_PARSE:
		return ( "Error: could not parse csv file." );
	case NUMBER_NOT_POSITIVE:
		return ( "Error: not a positive number." );
	case NUMBER_TOO_LARGE:
		return ( "Error: too large a number." );
	case BAD_INPUT:
		return ( "Error: bad input" );
	default:
		return ( "Error" );
	}
}

BitcoinExchange::BitcoinExchange( void )
{}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
{
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &other )
{
	if ( this != &other )
		data_ = other.data_;
	return ( *this );
}

BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::parseData( void )
{
	std::ifstream	ifs( "data.csv", std::ios::in );
	std::string		line;

	if ( !ifs.is_open() )
		throw Error( Error::FILE_CSV_COULD_NOT_OPEN );
	std::getline( ifs, line );
	if ( line != "date,exchange_rate" )
	{
		ifs.close();
		throw Error( Error::FILE_CSV_COULD_NOT_PARSE );
	}
	while ( !std::getline( ifs, line ).eof() && !line.empty() )
	{
		std::stringstream	ss( line );
		std::string			date;
		std::string			value;
		int					l_comma;

		l_comma = 0;
		while ( !std::getline( ss, value, ',' ).eof() )
		{
			if ( !l_comma )
				date = value;
			l_comma++;
		}
		if ( l_comma != 2 )
			break ;
		data_.insert( date, value );
	}
	if ( !ifs.eof() )
	{
		ifs.close();
		throw Error( Error::FILE_CSV_COULD_NOT_PARSE );
	}
}
