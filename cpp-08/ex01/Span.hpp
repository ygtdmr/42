/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:29:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 14:26:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <exception>

class Span
{
public:
	class LimitExceededException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class InsufficientElementsException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	Span( void );
	Span( unsigned int length );
	Span( const Span &other );
	~Span();
	Span	&operator=( const Span &other );
	void	addNumber( int number );
	template <typename I>
	void	addNumber( I begin, I end )
	{
		if ( ( std::distance( begin, end ) + numbers_.size() ) > length_ )
			throw LimitExceededException();
		numbers_.insert(numbers_.end(), begin, end);
	}
	int		shortestSpan( void );
	int		longestSpan( void );
private:
	std::vector<int>	numbers_;
	unsigned int		length_;
};

#endif
