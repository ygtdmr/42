/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 13:23:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
	static const int	fractionalBits_ = 8;
	int					rawBits_;
};

#endif
