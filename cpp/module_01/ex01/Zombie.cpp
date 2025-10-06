/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:32:57 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 08:16:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( void ){}

Zombie::~Zombie( void )
{
	std::cout << name_ << ": destroyed." << std::endl;
}

void	Zombie::setName( const std::string &name )
{
	name_ = name;
}

void	Zombie::announce( void )
{
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
