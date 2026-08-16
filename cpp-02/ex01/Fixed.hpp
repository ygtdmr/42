/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/14 12:23:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed( int nbr );
	Fixed( float nbr );
	Fixed	&operator=( const Fixed &other );
	int		getRawBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
private:
	static const int	fractionalBits_;
	int					rawBits_;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
