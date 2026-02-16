/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:13:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/16 14:22:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class	ScalarConverter
{
	public:
		static void		convert( const std::string &literal );

	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &other );
		~ScalarConverter();
		ScalarConverter	&operator=( const ScalarConverter &other );
		static bool		isLimit( const std::string &literal );
		static bool		isChar( const std::string &literal );
		static bool		isInt( const std::string &literal );
		static bool		isDecimal( const std::string &literal );
		static bool		isFloat( const std::string &literal );
		static bool		isDouble( const std::string &literal );

};

#endif
