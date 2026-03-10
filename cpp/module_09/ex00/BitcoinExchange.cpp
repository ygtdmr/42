/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:08 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/10 16:14:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
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
{
	parseData();
	std::map<std::string, float>::iterator it;
	std::cout << "result: " << std::endl;
	for (it = data_.begin(); it != data_.end(); ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

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
	std::ifstream		ifs( "data.csv", std::ios::in );
	std::stringstream	ss;
	std::string			line;

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
		
		std::string	raw;
		std::string	date;
		float		value;
		int			comma;

		ss.clear();
		ss.str( line );
		comma = 0;
		while ( !std::getline( ss, raw, ',' ).eof() )
		{
			if ( !comma )
				date = raw;
			comma++;
		}
		if ( comma != 1 || !( isDate( date ) && isNumber( raw , false) ) )
			break ;
		ss.clear();
		ss.str( raw );
		ss >> value;
		data_[date] = value;
	}
	ifs.close();
	if ( !ifs.eof() )
		throw Error( Error::FILE_CSV_COULD_NOT_PARSE );
}

bool	BitcoinExchange::isDate( const std::string &str )
{
	std::stringstream	ss( str );
	std::string			raw;
	int					hyphen( 0 );
	int					y;
	int					m;

	if ( str.empty() )
		return ( false );
	while ( std::getline( ss, raw, '-' ) )
	{
		std::stringstream	ss_raw( raw );
		int					value;
		
		if ( ( hyphen > 2 ) || !isNumber( raw, true ) )
			return ( false );
		ss_raw >> value;
		switch ( hyphen )
		{
		case 0:
			y = value;
			break;
		case 1:
			if ( value > 12 || raw.size() != 2 )
				return (false);
			else
				m = value;
			break;
		case 2:
			// Gregoryen Calendar Rules...
			bool	d_28_or_29( m == 2 );
			bool	d_30( m == 4 || m == 6 || m == 9 || m == 11 );
			bool	d_31( !d_28_or_29 && !d_30 );
			if ( ( d_31 && ( value > 31 ) ) || ( d_30 && ( value > 30 ) ) )
				return ( false );
			if ( d_28_or_29 )
			{
				if ( ( ( y % 4 ) != 0 ) && value > 28 )
					return ( false );
				else if ( ( ( y % 100 ) != 0 ) && value > 29 )
					return ( false );
				else if ( ( ( y % 400 ) != 0 ) && value > 28 )
					return ( false );
				else if ( ( ( y % 400 ) == 0 ) && value > 29 )
					return ( false );
			}
			break;
		}
		hyphen++;
	}
	return ( true );
}

bool	BitcoinExchange::isNumber( const std::string &str, bool onlyDigit )
{
	bool	dot( false );

	if ( str.empty() )
		return ( false );
	for ( size_t i = 0; i < str.size(); i++ )
	{
		if ( !std::isdigit( str[i] ) )
		{
			if ( onlyDigit )
				return ( false );
			if ( ( str[i] == '.' ) && !dot && i && ( ( i + 1 ) != str.size() ) )
				dot = true;
			else
				return ( false );
		}
	}
	return ( true );
}
