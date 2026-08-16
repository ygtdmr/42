/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/10 19:03:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <exception>

# define BTC_INPUT_NUMBER_LIMIT 1000

class BitcoinExchange
{
public:
	class Error : public std::exception
	{
		public:
			const typedef enum
			{
				FILE_COULD_NOT_OPEN,
				FILE_CSV_COULD_NOT_OPEN,
				FILE_CSV_COULD_NOT_PARSE,
				NUMBER_NOT_POSITIVE,
				NUMBER_TOO_LARGE,
				BAD_INPUT,
				MISSING_HEADER
			}	TYPE;
			const TYPE	type;
		
			Error( TYPE type );
			virtual const char	*what() const throw();
	};
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &other );
	~BitcoinExchange();
	BitcoinExchange	&operator=( const BitcoinExchange &other );
	void	parseInput( char *path );
private:
	std::map<std::string, float>	data_;

	void	parseData( void );
	bool	isDate( const std::string &str );
	bool	isNumber( const std::string &str, bool onlyDigit );
	float	exchange( const std::string &date, float amount );
};

#endif
