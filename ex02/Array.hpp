/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:12:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/03 14:21:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T>
class Array
{
	public:
		class	OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ( "Array Exception: index is out of bounds" );
				}
		};

		Array( unsigned int n )
		{
			elements_ = new T[n]();
			length_ = n;
		}

		Array( void )
		: elements_( 0 ), length_( 0 )
		{}

		Array( const Array &other )
		: elements_( 0 ), length_( 0 )
		{
			*this = other;
		}

		Array<T>	&operator=( const Array<T> &other )
		{
			if (this != &other)
			{
				if ( this->elements_ )
					delete[] this->elements_;
				this->elements_ = new T[other.length_]();
				this->length_ = other.length_;
				for (size_t i = 0; i < other.length_; i++)
					this->elements_[i] = other.elements_[i];
			}
			return ( *this );
		}

		T	&operator[]( size_t index )
		{
			if ( index < length_ )
				return ( this->elements_[index] );
			throw OutOfBoundsException();
		}

		const T	&operator[]( size_t index ) const
		{
			if ( index < length_ )
				return ( this->elements_[index] );
			throw OutOfBoundsException();
		}

		size_t	size( void ) const
		{
			return ( length_ );
		}

		~Array()
		{
			if ( elements_ )
				delete[] elements_;
		}
	private:
		T		*elements_;
		size_t	length_;
};


#endif
