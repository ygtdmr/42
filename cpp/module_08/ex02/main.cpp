/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:53:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/03/08 15:58:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.tpp"

int	main( void )
{
	std::cout << "--- subject test ---" << std::endl;
	MutantStack<int>	mstack;
	
	mstack.push( 5 );
	mstack.push( 17 );
	
	std::cout << "top element: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "size: " << mstack.size() << std::endl;
	
	mstack.push( 3 );
	mstack.push( 5 );
	mstack.push( 737 );
	// [...]
	mstack.push( 0 );
	
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "stack content:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s( mstack );


	std::cout << "--- std::list comparison ---" << std::endl;
	std::list<int>	mlist;
	
	mlist.push_back( 5 );
	mlist.push_back( 17 );
	
	std::cout << "top element: " << mlist.back() << std::endl;
	
	mlist.pop_back();
	
	std::cout << "size: " << mlist.size() << std::endl;
	
	mlist.push_back( 3 );
	mlist.push_back( 5 );
	mlist.push_back( 737 );
	// [...]
	mlist.push_back( 0 );
	
	std::list<int>::iterator	lit = mlist.begin();
	std::list<int>::iterator	lite = mlist.end();
	
	++lit;
	--lit;
	
	std::cout << "list content:" << std::endl;
	while ( lit != lite )
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	return ( 0 );
}
