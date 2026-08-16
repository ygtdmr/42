/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:28:03 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 15:58:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
	
		MutantStack( void )
		: std::stack<T>()
		{}
		MutantStack( const MutantStack &other )
		: std::stack<T>( other )
		{}
		~MutantStack()
		{}
		MutantStack	&operator=( const MutantStack &other )
		{
			if (this != &other)
				std::stack<T>::operator=( other );
			return ( *this );
		}
		iterator begin( void )
		{
			return ( this->c.begin() );
		}
		iterator end( void )
		{
			return ( this->c.end() );
		}
};

#endif
