/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:08 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/10 20:06:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "BitcoinExchange.hpp"

BitcoinExchange::Error::Error( TYPE type )
: type( type )
{}

const char	*BitcoinExchange::Error::what() const throw()
{
	switch ( type )
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
	case MISSING_HEADER:
		return ( "Error: missing header." );
	default:
		return ( "Error" );
	}
}

BitcoinExchange::BitcoinExchange( void )
{
	parseData();
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

bool	BitcoinExchange::isDate( const std::string &str )
{
	size_t		y_pos;
	size_t		m_pos;
	std::string	y_str;
	std::string	m_str;
	std::string	d_str;
	int			y;
	int			m;
	int			d;

	if ( str.empty() )
		return ( false );
	y_pos = str.find('-');
	if ( y_pos == std::string::npos )
		return ( false );
	m_pos = str.find('-', y_pos + 1);
	if ( m_pos == std::string::npos )
		return ( false );
	y_str = str.substr( 0, y_pos );
	m_str = str.substr( y_pos + 1, 2 );
	d_str = str.substr( m_pos + 1 );

	if ( !( isNumber( y_str, true ) && isNumber( m_str, true ) && isNumber( d_str, true ) ) )
		return ( false );

	y = atoi( y_str.c_str() );
	m = atoi( m_str.c_str() );
	d = atoi( d_str.c_str() );

	if ( m > 12 )
		return ( false );
	if ( !( ( m_str.size() == 2 ) && ( d_str.size() == 2 ) ) )
		return ( false );

	bool	d_28_or_29( m == 2 );
	bool	d_30( m == 4 || m == 6 || m == 9 || m == 11 );
	bool	d_31( !d_28_or_29 && !d_30 );

	if ( ( d_31 && ( d > 31 ) ) || ( d_30 && ( d > 30 ) ) )
		return ( false );
	if ( d_28_or_29 )
	{
		if ( ( ( y % 4 ) != 0 ) && d > 28 )
			return ( false );
		else if ( ( ( y % 100 ) != 0 ) && d > 29 )
			return ( false );
		else if ( ( ( y % 400 ) != 0 ) && d > 28 )
			return ( false );
		else if ( ( ( y % 400 ) == 0 ) && d > 29 )
			return ( false );
	}
	return ( true );
}

bool	BitcoinExchange::isNumber( const std::string &str, bool onlyDigit )
{
	bool	dot( false );
	bool	sign( false );

	if ( str.empty() )
		return ( false );
	for ( size_t i = 0; i < str.size(); i++ )
	{
		if ( !std::isdigit( str[i] ) )
		{
			if ( ( str[i] == '-' || str[i] == '+' ) && !sign && !i )
				sign = true;
			else if ( onlyDigit )
				return ( false );
			else if ( ( str[i] == '.' ) && !dot && i && ( ( i + 1 ) != str.size() ) )
				dot = true;
			else
				return ( false );
		}
	}
	return ( true );
}

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
		
		std::string	date;
		std::string	value;
		size_t		comma_pos( line.find(",") );

		date = line.substr(0, comma_pos);
		value = line.substr(comma_pos + 1);
		if ( !( ( value[0] != '-' ) && isDate( date ) && isNumber( value, false ) ) )
			break ;
		data_[date] = static_cast<float>( atof( value.c_str() ) );
	}
	ifs.close();
	if ( !ifs.eof() )
		throw Error( Error::FILE_CSV_COULD_NOT_PARSE );
}

float	BitcoinExchange::exchange( const std::string &date, float amount )
{
	std::map<std::string, float>::iterator	it( data_.find( date ) );

	if ( it == data_.end() )
	{
		it = data_.lower_bound( date );
		if ( it != data_.begin() )
			--it;
	}
	return ( it->second * amount );
}

void	BitcoinExchange::parseInput( char *path )
{
	std::ifstream	ifs( path, std::ios::in );
	std::string		line;

	if ( !ifs.is_open() )
		throw Error( Error::FILE_COULD_NOT_OPEN );
	std::getline( ifs, line );
	if ( line != "date | value" )
	{
		ifs.close();
		throw Error( Error::MISSING_HEADER );
	}
	while ( std::getline( ifs, line ) )
	{
		try
		{
			std::string	date;
			std::string	value;
			size_t		pipe_pos( line.find(" | ") );
			float		f_value;

			if ( pipe_pos == std::string::npos )
				throw Error( Error::BAD_INPUT );
			date = line.substr(0, pipe_pos);
			value = line.substr(pipe_pos + 3);
			if ( !( isDate( date ) && isNumber( value, false ) ) )
				throw Error( Error::BAD_INPUT );
			f_value = static_cast<float>( atof( value.c_str() ) );
			if ( f_value < 0 )
				throw Error( Error::NUMBER_NOT_POSITIVE );
			if ( f_value > BTC_INPUT_NUMBER_LIMIT )
				throw Error( Error::NUMBER_TOO_LARGE );
			std::cout
				<< date
				<< " => "
				<< f_value
				<< " = "
				<< exchange( date, f_value )
				<< std::endl;
		}
		catch( const Error& e )
		{
			if ( e.type == Error::BAD_INPUT )
				std::cerr << e.what() << " => " << line << std::endl;
			else
				std::cerr << e.what() << std::endl;
		}
	}
}
