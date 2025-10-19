/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:10:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:39:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void )
{
	len_inv_ = 0;
}

Character::Character( const Character &other )
{
	*this = other;
}

Character::Character( const std::string &name )
{
	name_ = name;
}

Character::~Character()
{}

Character	&Character::operator=( const Character &other )
{
	len_inv_ = other.len_inv_;
	for (size_t i = 0; i < CHARACTER_INV_MAX; i++)
	{
		delete inventory_[i];
		inventory_[i] = other.inventory_[i];
	}
	return ( *this );
}

std::string const	&Character::getName( void ) const
{
	return ( name_ );
}

void	Character::equip( AMateria *m )
{
	if (len_inv_ >= CHARACTER_INV_MAX)
		return ;
	inventory_[len_inv_] = m;
	len_inv_++;
}
void	Character::unequip( int idx )
{
	inventory_[idx] = 0;
}
void	Character::use( int idx, ICharacter &target )
{
	if (idx >= len_inv_)
		return ;
	inventory_[idx]->use(target);
}
