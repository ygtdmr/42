/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:07:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	std::cout 
		<< "Brain constructed."
		<< std::endl;
}

Brain::Brain( const Brain &other )
{
	std::cout 
		<< "Brain constructed."
		<< std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout 
		<< "Brain destroyed."
		<< std::endl;
}

Brain	&Brain::operator=( const Brain &other )
{
	if ( this != &other )
	{
		for ( size_t i = 0; i < BRAIN_IDEA_LENGTH; i++ )
			this->ideas[i] = other.ideas[i];
	}
	return ( *this );
}
