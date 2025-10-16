/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 14:51:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void )
: name_("unnamed"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout 
		<< "ClapTrap "
		<< name_
		<< " constructed."
		<< std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout 
		<< "ClapTrap "
		<< name_
		<< " destroyed."
		<< std::endl;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &other )
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

ClapTrap::ClapTrap( const std::string &name )
: name_( name ), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout 
		<< "ClapTrap "
		<< name_
		<< " constructed."
		<< std::endl;
	
}

void	ClapTrap::attack( const std::string& target )
{
	if (hitPoints_ <= 0 || energyPoints_ <= 0)
	{
		std::cout
			<< "ClapTrap "
			<< name_
			<< " has no energy/hit points left to attack!"
			<< std::endl;
		return ;
	}
	energyPoints_ --;
	std::cout
		<< "ClapTrap "
		<< name_ 
		<< " attacks "
		<< target
		<< ", causing "
		<< attackDamage_
		<< " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (hitPoints_ > 0)
	{
		hitPoints_ -= amount;
		if (hitPoints_ < 0)
			hitPoints_ = 0;
	}
	else
	{
		std::cout
			<< "ClapTrap "
			<< name_
			<< " has no hit points left to take damage!"
			<< std::endl;
		return ;
	}
	std::cout
		<< "ClapTrap "
		<< name_
		<< " takes "
		<< amount
		<< " points of damage!"	
		<< std::endl;
}
void	ClapTrap::beRepaired( unsigned int amount )
{
	if (hitPoints_ <= 0 || energyPoints_ <= 0)
	{
		std::cout
			<< "ClapTrap "
			<< name_
			<< " has no energy/hit points left to be repaired!"
			<< std::endl;
		return ;
	}
	energyPoints_ --;
	hitPoints_ += amount;
	std::cout
		<< "ClapTrap "
		<< name_
		<< " repairs itself, recovering "
		<< amount
		<< " hit points!"
		<< std::endl;
}
