/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:42:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void )
{}

AMateria::AMateria( const AMateria &other )
{
	*this = other;
}

AMateria::~AMateria()
{}

AMateria	&AMateria::operator=( const AMateria &other )
{
	if ( this != &other )
	{
		this->type_ = other.type_;
	}
	return ( *this );
}

std::string const &AMateria::getType( void ) const
{
	return ( type_ );
}

void	AMateria::use( ICharacter &target )
{
	( void ) target;
	std::cout
		<< "* detected use from unknown type of AMateria *"
		<< std::endl;
}
