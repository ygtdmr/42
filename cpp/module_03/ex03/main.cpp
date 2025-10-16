/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 04:57:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 15:56:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	diamond("Bob");

	std::cout << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	return (0);
}
