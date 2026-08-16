/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 14:49:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog( void )
{
	std::cout 
		<< "Dog constructed."
		<< std::endl;
	type_ = "Dog";
}

Dog::Dog( const Dog &other )
{
	*this = other;
	std::cout 
		<< "Dog constructed."
		<< std::endl;
}

Dog::~Dog()
{
	std::cout 
		<< "Dog destroyed."
		<< std::endl;
}

Dog	&Dog::operator=( const Dog &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout
		<< "Woof! Woof!"
		<< std::endl;
}
