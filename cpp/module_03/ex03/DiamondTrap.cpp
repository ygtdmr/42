/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:12:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 15:52:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
: ClapTrap("unnamed_clap_name" ), FragTrap(), ScavTrap()
{
	_name = "unnamed";
	hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
    std::cout
		<< "DiamondTrap "
		<< _name
		<< " constructed."
		<< std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other )
{
	*this = other;
	std::cout
		<< "DiamondTrap "
		<< _name
		<< " constructed."
		<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout 
		<< "DiamondTrap "
		<< _name
		<< " destroyed."
		<< std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &other )
{
	if ( this != &other )
	{
		this->_name = other._name;
		this->hitPoints_ = other.hitPoints_;
		this->energyPoints_ = other.energyPoints_;
		this->attackDamage_ = other.attackDamage_;
	}
	return ( *this );
}

DiamondTrap::DiamondTrap( const std::string &name ) 
: ClapTrap( name + "_clap_name" ), FragTrap( name ), ScavTrap( name )
{
	_name = name;
	hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
    std::cout
		<< "DiamondTrap "
		<< _name
		<< " constructed."
		<< std::endl;
}

void DiamondTrap::whoAmI( void )
{
	std::cout
		<< "DiamondTrap " 
		<< _name
		<< " says: My name is "
		<< _name
		<< " and my ClapTrap name is "
		<< ClapTrap::name_
		<< std::endl;
}
