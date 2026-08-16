/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 06:51:38 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 08:14:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int main( void )
{
	Zombie	*horde;
	int		N;

	N = 8;
	horde = zombieHorde(N, "danger horde");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
