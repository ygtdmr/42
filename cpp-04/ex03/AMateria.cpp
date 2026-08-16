/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:18:05 by yidemir          ###   ########.fr       */
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

AMateria::AMateria( std::string const &type )
{
	type_ = type;
}

AMateria::~AMateria()
{}

AMateria	&AMateria::operator=( const AMateria &other )
{
	if ( this != &other )
		this->type_ = other.type_;
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
		<< "* uses unknown materia *"
		<< std::endl;
}
