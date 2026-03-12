/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:02:26 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/12 18:59:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <exception>
#include "PmergeMe.hpp"

#include <iostream>

PmergeMe::PmergeMe( void )
{}

PmergeMe::PmergeMe( const PmergeMe &other )
{
	*this = other;
}

PmergeMe	&PmergeMe::operator=( const PmergeMe &other )
{
	if ( this != &other )
	{
		vector_ = other.vector_;
		deque_ = other.deque_;
	}
	return ( *this );
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::parse( char **argv )
{
	std::stringstream	ss;
	std::string			tmp_s;

	while ( *argv )
		ss << *( argv++ ) << " ";
	if ( ss.str().empty() )
		throw std::exception();
	while ( ss >> tmp_s )
	{
		double	tmp_d;
		int		nbr;

		for (size_t i = 0; i < tmp_s.size(); i++)
		{
			if ( !std::isdigit( tmp_s[i] ) )
				throw std::exception();
		}
		tmp_d = std::strtod( tmp_s.c_str(), 0 );
		if ( !( tmp_d > 0 && tmp_d <= INT_MAX ) )
			throw std::exception();
		nbr = static_cast<int>( tmp_d );
		vector_.push_back( nbr );
		deque_.push_back( nbr );
	}
}

void	PmergeMe::sort( char **argv )
{
	parse( argv );
	for (size_t i = 0; i < vector_.size(); i++)
	{
		std::cout << vector_[i] << ", ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < deque_.size(); i++)
	{
		std::cout << deque_[i] << ", ";
	}
	std::cout << std::endl;
	
}
