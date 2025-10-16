/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 14:11:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout 
		<< "ScavTrap "
		<< name_
		<< " constructed."
		<< std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other)
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout 
		<< "ScavTrap "
		<< name_
		<< " destroyed."
		<< std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &other )
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

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 50;
	attackDamage_ = 20;
	std::cout 
		<< "ScavTrap "
		<< name_
		<< " constructed."
		<< std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout
		<< "ScavTrap "
		<< name_
		<< " is now in Gate Keeper mode."
		<< std::endl;
}

void ScavTrap::attack( const std::string& target )
{
	if (hitPoints_ <= 0 || energyPoints_ <= 0)
	{
		std::cout
			<< "ScavTrap "
			<< name_
			<< " has no energy/hit points left to attack!"
			<< std::endl;
		return ;
	}
	energyPoints_--;
	std::cout
		<< "ScavTrap "
		<< name_
		<< " fiercely attacks "
		<< target
		<< ", causing "
		<< attackDamage_
		<< " points of damage!"
		<< std::endl;
}
