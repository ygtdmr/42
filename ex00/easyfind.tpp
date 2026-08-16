/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 19:22:24 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 11:27:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <algorithm>

class	NotFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ( "easyfind exception: target value not found" );
		}
};

template<typename T>
typename T::iterator	easyfind( T &container, int value )
{
	typename T::iterator	it;

	it = std::find( container.begin(), container.end(), value );
	if ( it == container.end() )
		throw NotFoundException();
	return ( it );
}
