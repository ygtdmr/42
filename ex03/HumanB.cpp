/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:39:53 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/07 14:07:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( const std::string &name )
{
	name_ = name;
	weapon_ = 0;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	weapon_ = &weapon;
}

void	HumanB::attack( void )
{
	if (weapon_)
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
	else
		std::cout << name_ << " cannot attack because of have no weapon "  << std::endl;
}
