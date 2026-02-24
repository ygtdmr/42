/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:27:16 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/24 18:09:17 by yidemir          ###   ########.fr       */
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
		static void		print( const std::string &literal, bool error, const double &raw );
		static bool		isPseudo( const std::string &literal, char type = 'a' );
};

#endif
