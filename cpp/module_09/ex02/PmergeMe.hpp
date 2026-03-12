/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:02:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/12 18:59:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
public:
	PmergeMe( void );
	PmergeMe( const PmergeMe &other );
	~PmergeMe();
	PmergeMe	&operator=( const PmergeMe &other );
	void		sort( char **argv );
private:
	std::vector<int>	vector_;
	std::deque<int>		deque_;
	
	void	parse( char **argv );
};

#endif
