/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:10:05 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 16:05:06 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure( void ) : AMateria("cure")
{}

Cure::Cure( const Cure &other ) : AMateria(other)
{
	*this = other;
}

Cure::~Cure()
{}

Cure	&Cure::operator=( const Cure &other )
{
	if ( this != &other )
		this->type_ = other.type_;
	return ( *this );
}

AMateria	*Cure::clone( void ) const
{
	return ( new Cure(*this) );
}

void	Cure::use( ICharacter &target )
{
	std::cout
		<< "* heals "
		<< target.getName()
		<< "'s wounds *"
		<< std::endl;
}
