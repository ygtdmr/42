/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:29:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/03 11:59:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
const T	&min(const T &a, const T &b )
{
	if ( a < b )
		return ( a );
	return ( b );
}

template <typename T>
const T	&max( const T &a, const T &b )
{
	if ( a > b )
		return ( a );
	return ( b );
}

template <typename T>
void	swap( T &a, T &b )
{
	T	tmp( a );
	a = b;
	b = tmp;
}

#endif
