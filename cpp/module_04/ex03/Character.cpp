/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:10:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 16:00:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character( void )
{
	for (size_t i = 0; i < CHARACTER_INV_MAX; i++)
		inventory_[i] = 0;
}

Character::Character( const Character &other ) : ICharacter(other)
{
	*this = other;
}

Character::Character( const std::string &name )
{
	name_ = name;
	for (size_t i = 0; i < CHARACTER_INV_MAX; i++)
		inventory_[i] = 0;
}

Character::~Character()
{
	for (size_t i = 0; i < CHARACTER_INV_MAX; i++)
		delete inventory_[i];
}

Character	&Character::operator=( const Character &other )
{
	if (this != &other)
	{
		name_ = other.name_;
		for (int i = 0; i < CHARACTER_INV_MAX; i++)
		{
			delete inventory_[i];
			if (other.inventory_[i])
				inventory_[i] = other.inventory_[i]->clone();
			else
				inventory_[i] = 0;
		}
	}
	return ( *this );
}

std::string const	&Character::getName( void ) const
{
	return ( name_ );
}

void	Character::equip( AMateria *m )
{
	if (!m)
		return ;
	for (size_t i = 0; i < CHARACTER_INV_MAX; i++)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			return ;
		}
	}
}
void	Character::unequip( int idx )
{
	if (idx >= 0 && idx < CHARACTER_INV_MAX)
		inventory_[idx] = 0;
}
void	Character::use( int idx, ICharacter &target )
{
	if ((idx >= 0 && idx < CHARACTER_INV_MAX) && inventory_[idx])
		inventory_[idx]->use(target);
}
