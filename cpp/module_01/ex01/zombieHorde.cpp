/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 07:30:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 08:19:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <sstream>

Zombie*	zombieHorde( int N, std::string name )
{
	std::ostringstream	sstream;
	Zombie				*horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		sstream << name << " " << i;
		horde[i].setName(sstream.str());
		sstream.str("");
		sstream.clear();
	}
	return (horde);
}
