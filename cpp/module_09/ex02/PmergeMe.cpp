/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:02:26 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/20 13:14:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <exception>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "PmergeMe.hpp"

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

void	PmergeMe::parse( int argc, char **argv )
{
	std::stringstream	ss;
	std::string			tmp_s;

	if ( argc == 1 )
		throw std::exception();
	while ( *argv )
		ss << *( argv++ ) << " ";
	while ( ss >> tmp_s )
	{
		double	tmp_d;
		int		nbr;
		bool	isSign( ( tmp_s.size() > 1 ) && ( ( tmp_s[0] == '+' ) || ( tmp_s[0] == '-' ) ) );

		for (size_t i = isSign; i < tmp_s.size(); i++)
		{
			if ( !std::isdigit( tmp_s[i] ) )
				throw std::exception();
		}
		tmp_d = std::strtod( tmp_s.c_str(), 0 );
		if ( !( tmp_d >= 0 && tmp_d <= INT_MAX ) )
			throw std::exception();
		nbr = static_cast<int>( tmp_d );
		vector_.push_back( nbr );
		deque_.push_back( nbr );
	}
	if ( vector_.empty() || deque_.empty() )
		throw std::exception();
}

void	PmergeMe::printSequence( const std::string& message ) const
{
	size_t	length( PMERGE_ME_NUMBERS_LIMIT - 1 );

	if ( vector_.size() <= PMERGE_ME_NUMBERS_LIMIT )
		length = vector_.size();
	std::cout
		<< message;
	for ( size_t i = 0; i < length; i++ )
	{
		std::cout << vector_[i];
		if ( ( i + 1 ) < length )
			std::cout
				<< " ";
	}
	if ( vector_.size() > PMERGE_ME_NUMBERS_LIMIT )
		std::cout
			<< " [...]";
	std::cout
		<< std::endl;
}

size_t	PmergeMe::getJacobsthal( size_t n ) const
{
	size_t	prev2( 0 );
    size_t	prev1( 1 );
    size_t	current( 0 );

    if (n == 0)
		return ( 0 );
    if (n == 1)
		return ( 1 );
    for ( size_t i = 2; i <= n; ++i )
	{
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return ( current );
}

void	PmergeMe::fordJohnsonAlgorithm( std::vector<int> &arr )
{
	size_t	n( arr.size() );

	if (n < 2)
		return ;

	bool	hasStraggler( n % 2 != 0 );
	int		straggler;

	if ( hasStraggler )
	{
		straggler = arr.back();
		arr.pop_back();
		n--;
	}

	std::vector< std::pair<int, int> >	pairs;
	std::vector<int>					mainChain;

	for ( size_t i = 0; i < n; i += 2 )
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back( std::make_pair( arr[i], arr[i + 1] ) );
		else
			pairs.push_back( std::make_pair( arr[i + 1], arr[i] ) );
	}

	for ( size_t i = 0; i < pairs.size(); ++i )
		mainChain.push_back( pairs[i].first );
	
	fordJohnsonAlgorithm( mainChain );

	std::vector<int>	pending;
	for ( size_t i = 0; i < mainChain.size(); ++i )
	{
		for ( size_t j = 0; j < pairs.size(); ++j )
		{
			if ( mainChain[i] == pairs[j].first )
			{
				pending.push_back( pairs[j].second );
				pairs[j].first = -1; 
				break ;
			}
		}
	}
	std::vector<int>	sortedArr( mainChain );

	if ( !pending.empty() )
		sortedArr.insert( sortedArr.begin(), pending[0] );

	size_t	pendSize( pending.size() );
	size_t	jacobIndex( 3 );
	size_t	prevJacob( 1 );
	size_t	currJacob( getJacobsthal( jacobIndex ) );

	while ( prevJacob < pendSize )
	{
		size_t  limit;

		if ( currJacob > pendSize )
			limit = pendSize;
		else
			limit = currJacob;

		for ( size_t i = limit; i > prevJacob; --i )
		{
			int							valToInsert( pending[i - 1] );
			std::vector<int>::iterator	it( std::lower_bound( sortedArr.begin(), sortedArr.end(), valToInsert ) );

			sortedArr.insert( it, valToInsert );
		}

		prevJacob = currJacob;
		jacobIndex++;
		currJacob = getJacobsthal( jacobIndex );
	}

	if ( hasStraggler )
	{
		std::vector<int>::iterator	it = std::lower_bound( sortedArr.begin(), sortedArr.end(), straggler );
		sortedArr.insert( it, straggler );
	}

	arr = sortedArr;
}

void	PmergeMe::fordJohnsonAlgorithm( std::deque<int> &arr )
{
	size_t	n( arr.size() );

	if (n < 2)
		return ;

	bool	hasStraggler( n % 2 != 0 );
	int		straggler;

	if ( hasStraggler )
	{
		straggler = arr.back();
		arr.pop_back();
		n--;
	}

	std::deque< std::pair<int, int> >	pairs;
	std::deque<int>					mainChain;

	for ( size_t i = 0; i < n; i += 2 )
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back( std::make_pair( arr[i], arr[i + 1] ) );
		else
			pairs.push_back( std::make_pair( arr[i + 1], arr[i] ) );
	}

	for ( size_t i = 0; i < pairs.size(); ++i )
		mainChain.push_back( pairs[i].first );
	
	fordJohnsonAlgorithm( mainChain );

	std::deque<int>	pending;
	for ( size_t i = 0; i < mainChain.size(); ++i )
	{
		for ( size_t j = 0; j < pairs.size(); ++j )
		{
			if ( mainChain[i] == pairs[j].first )
			{
				pending.push_back( pairs[j].second );
				pairs[j].first = -1; 
				break ;
			}
		}
	}
	std::deque<int>	sortedArr( mainChain );

	if ( !pending.empty() )
		sortedArr.insert( sortedArr.begin(), pending[0] );

	size_t	pendSize( pending.size() );
	size_t	jacobIndex( 3 );
	size_t	prevJacob( 1 );
	size_t	currJacob( getJacobsthal( jacobIndex ) );

	while ( prevJacob < pendSize )
	{
		size_t  limit;

		if ( currJacob > pendSize )
			limit = pendSize;
		else
			limit = currJacob;

		for ( size_t i = limit; i > prevJacob; --i )
		{
			int							valToInsert( pending[i - 1] );
			std::deque<int>::iterator	it( std::lower_bound( sortedArr.begin(), sortedArr.end(), valToInsert ) );

			sortedArr.insert( it, valToInsert );
		}

		prevJacob = currJacob;
		jacobIndex++;
		currJacob = getJacobsthal( jacobIndex );
	}

	if ( hasStraggler )
	{
		std::deque<int>::iterator	it = std::lower_bound( sortedArr.begin(), sortedArr.end(), straggler );
		sortedArr.insert( it, straggler );
	}

	arr = sortedArr;
}

void	PmergeMe::sortAndPrint( void )
{
    printSequence( "Before:	" );

    clock_t	startVec( std::clock() );
    fordJohnsonAlgorithm( vector_ );
    clock_t	endVec( std::clock() );
    double	timeVec( static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0 );

    clock_t	startDeq( std::clock() );
    fordJohnsonAlgorithm( deque_ );
    clock_t	endDeq( std::clock() );
    double	timeDeq( static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0 );

    printSequence( "After:	" );

    std::cout
		<< std::fixed
		<< std::setprecision(5);

    std::cout
		<< "Time to process a range of "
		<< vector_.size()
        << " elements with std::vector : "
		<< timeVec
		<< " us"
		<< std::endl;

    std::cout
		<< "Time to process a range of "
		<< deque_.size()
        << " elements with std::deque  : "
		<< timeDeq
		<< " us"
		<< std::endl;
}
