/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:39:53 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/07 14:23:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( const std::string &name, Weapon &weapon )
:weapon_(weapon)
{
	name_ = name;
}

void	HumanA::attack( void )
{
	std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}
