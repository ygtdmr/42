/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:42:57 by yidemir          ###   ########.fr       */
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
	brain_ = new Brain();
}

Cat::Cat( const Cat &other )
{
	type_ = other.type_;
	brain_ = new Brain(*other.brain_);
	std::cout 
		<< "Cat constructed."
		<< std::endl;
}

Cat::~Cat()
{
	delete brain_;
	std::cout 
		<< "Cat destroyed."
		<< std::endl;
}

Cat	&Cat::operator=( const Cat &other )
{
	if ( this != &other )
	{
		delete brain_;
		brain_ = new Brain(*other.brain_);
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
