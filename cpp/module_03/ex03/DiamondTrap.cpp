/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:12:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 16:37:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
: ClapTrap("unnamed_clap_name" ), FragTrap(), ScavTrap()
{
	this->name_ = "unnamed";
	hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
    std::cout
		<< "DiamondTrap "
		<< this->name_
		<< " constructed."
		<< std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other )
: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this = other;
	std::cout
		<< "DiamondTrap "
		<< this->name_
		<< " constructed."
		<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout 
		<< "DiamondTrap "
		<< this->name_
		<< " destroyed."
		<< std::endl;
}

DiamondTrap	&DiamondTrap::operator=( const DiamondTrap &other )
{
	if ( this != &other )
	{
		this->name_ = other.name_;
		this->hitPoints_ = other.hitPoints_;
		this->energyPoints_ = other.energyPoints_;
		this->attackDamage_ = other.attackDamage_;
	}
	return ( *this );
}

DiamondTrap::DiamondTrap( const std::string &name ) 
: ClapTrap( name + "_clap_name" ), FragTrap( name ), ScavTrap( name )
{
	this->name_ = name;
	hitPoints_ = FragTrap::hitPoints_;
    energyPoints_ = ScavTrap::energyPoints_;
    attackDamage_ = FragTrap::attackDamage_;
    std::cout
		<< "DiamondTrap "
		<< this->name_
		<< " constructed."
		<< std::endl;
}

void DiamondTrap::whoAmI( void )
{
	std::cout
		<< "DiamondTrap " 
		<< this->name_
		<< " says: My name is "
		<< this->name_
		<< " and my ClapTrap name is "
		<< ClapTrap::name_
		<< std::endl;
}
