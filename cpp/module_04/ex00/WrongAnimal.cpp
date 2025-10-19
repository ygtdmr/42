/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 14:49:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void )
{
	std::cout 
		<< "WrongAnimal constructed."
		<< std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
	*this = other;
	std::cout 
		<< "WrongAnimal constructed."
		<< std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout 
		<< "WrongAnimal destroyed."
		<< std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout 
		<< "Any wrong animal sound..."
		<< std::endl;
}

const std::string	&WrongAnimal::getType( void ) const
{
	return (type_);
}
