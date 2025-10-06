/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:51:38 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 07:16:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int main( void )
{
	Zombie	zombie_a("zomibe_a");
	Zombie	*zombie_b;

	zombie_a.announce();
	zombie_b = newZombie("zombie_b");
	zombie_b->announce();
	delete zombie_b;
	randomChump("zombie_c");
}
