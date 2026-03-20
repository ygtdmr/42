/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:02:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/20 13:11:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <string>
# include <vector>
# include <deque>

# define PMERGE_ME_NUMBERS_LIMIT 5

class PmergeMe
{
public:
	PmergeMe( void );
	PmergeMe( const PmergeMe &other );
	~PmergeMe();
	PmergeMe	&operator=( const PmergeMe &other );
	void	parse( int argc, char** argv );
    void	sortAndPrint( void );
private:
	std::vector<int>	vector_;
	std::deque<int>		deque_;

	void	fordJohnsonAlgorithm( std::vector<int> &arr );
    void	fordJohnsonAlgorithm( std::deque<int> &arr );
	size_t	getJacobsthal( size_t n ) const;
	void	printSequence( const std::string& message ) const;
};

#endif
