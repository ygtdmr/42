/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 15:14:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout 
		<< "FragTrap "
		<< name_
		<< " constructed."
		<< std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other)
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout 
		<< "FragTrap "
		<< name_
		<< " constructed."
		<< std::endl;
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout 
		<< "FragTrap "
		<< name_
		<< " destroyed."
		<< std::endl;
}

FragTrap	&FragTrap::operator=( const FragTrap &other )
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

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name)
{
	hitPoints_ = 100;
	energyPoints_ = 100;
	attackDamage_ = 30;
	std::cout 
		<< "FragTrap "
		<< name_
		<< " constructed."
		<< std::endl;
}

void	FragTrap::highFivesGuys( void )
{
		std::cout
			<< "FragTrap "
			<< name_
			<< " requests a positive high five!"
			<< std::endl;
}
