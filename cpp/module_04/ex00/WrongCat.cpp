/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 14:31:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void )
{
	std::cout 
		<< "WrongCat constructed."
		<< std::endl;
	type_ = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &other )
{
	*this = other;
	type_ = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout 
		<< "WrongCat destroyed."
		<< std::endl;
}

WrongCat	&WrongCat::operator=( const WrongCat &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

void	WrongCat::makeSound( void ) const
{
	std::cout
		<< "Wrong Meooow!"
		<< std::endl;
}
