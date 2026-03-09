/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:14:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/09 20:00:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <exception>

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
				BAD_INPUT
			}	TYPE;
			Error( TYPE type );
			virtual const char	*what() const throw();
		private:
			const TYPE	type_;
	};
	BitcoinExchange( void );
	BitcoinExchange( const BitcoinExchange &other );
	~BitcoinExchange();
private:
	std::map<std::string, int>	data_;

	void	parseData( void );
};

#endif
