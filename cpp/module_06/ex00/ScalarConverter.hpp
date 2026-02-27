/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:27:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/27 18:56:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter
{
	public:
		static void	convert( const std::string &literal );

	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &other );
		~ScalarConverter();
		ScalarConverter	&operator=( const ScalarConverter &other );
		static void	printChar( const double &raw, const bool isError );
		static void	printInt( const double &raw, const bool isError );
		static void	printFloat( const double &raw, const bool isError );
		static void	printDouble( const double &raw, const bool isError );
		static void	printErr( void );
		static char	literalType( const std::string &literal );
		static bool	isPseudoDouble( const std::string &literal );
		static bool	isPseudoFloat( const std::string &literal );
};

#endif
