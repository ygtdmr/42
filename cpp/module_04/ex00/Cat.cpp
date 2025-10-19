/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 14:20:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat( void )
{
	std::cout 
		<< "Cat constructed."
		<< std::endl;
	type_ = "Cat";
}

Cat::Cat( const Cat &other )
{
	*this = other;
	type_ = "Cat";
}

Cat::~Cat()
{
	std::cout 
		<< "Cat destroyed."
		<< std::endl;
}

Cat	&Cat::operator=( const Cat &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout
		<< "Meooow!"
		<< std::endl;
}
