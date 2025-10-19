/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:48:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice( void )
{}

Ice::Ice( const Ice &other )
{
	*this = other;
}

Ice::~Ice()
{}

Ice	&Ice::operator=( const Ice &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

AMateria	*Ice::clone( void ) const
{
	return ( new Ice(*this) );
}

void	Ice::use( ICharacter &target )
{
	std::cout
		<< "* shoots an ice bolt at "
		<< target.getName()
		<< " *"
		<< std::endl;
}
