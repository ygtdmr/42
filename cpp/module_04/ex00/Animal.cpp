/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 14:49:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal( void )
{
	std::cout 
		<< "Animal constructed."
		<< std::endl;
}

Animal::Animal( const Animal &other )
{
	std::cout 
		<< "Animal constructed."
		<< std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout 
		<< "Animal destroyed."
		<< std::endl;
}

Animal	&Animal::operator=( const Animal &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

void	Animal::makeSound( void ) const
{
	std::cout 
		<< "Any animal sound..."
		<< std::endl;
}

const std::string	&Animal::getType( void ) const
{
	return (type_);
}
