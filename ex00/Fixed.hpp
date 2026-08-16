/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/13 12:12:52 by yidemir          ###   ########.fr       */
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
	Fixed	&operator=( const Fixed &other );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
private:
	static const int	fractionalBits_ = 8;
	int					rawBits_;
};

#endif
