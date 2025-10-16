/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 04:57:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 12:38:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap	a("Bob");

    a.attack("TargetDummy");
    a.takeDamage(3);
    a.beRepaired(5);

    for (int i = 0; i < 10; i++)
        a.attack("TrainingBot");

    a.takeDamage(20);
    a.attack("Nothing");
    a.beRepaired(10);
	return (0);
}
