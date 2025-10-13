/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 16:26:43 by yidemir          ###   ########.fr       */
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
	
	Fixed				&operator=( const Fixed &other );
	Fixed				operator+( const Fixed &other ) const;
	Fixed				operator-( const Fixed &other ) const;
	Fixed				operator*( const Fixed &other ) const;
	Fixed				operator/( const Fixed &other ) const;
	Fixed				&operator++();
	Fixed				operator++( int );
	Fixed				&operator--();
	Fixed				operator--( int );
	bool				operator>( const Fixed &other ) const;
	bool				operator<( const Fixed &other ) const;
	bool				operator>=( const Fixed &other ) const;
	bool				operator<=( const Fixed &other ) const;
	bool				operator==( const Fixed &other ) const;
	bool				operator!=( const Fixed &other ) const;
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	float				toFloat( void ) const;
	int					toInt( void ) const;
	static Fixed		&min(Fixed &f1, Fixed &f2);
	static const Fixed	&min(const Fixed &f1, const Fixed &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static const Fixed	&max(const Fixed &f1, const Fixed &f2);
private:
	static const int	fractionalBits_;
	int					rawBits_;
};

#endif
