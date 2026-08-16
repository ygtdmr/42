/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 07:22:15 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/10 09:53:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
	map_[0] = &Harl::debug;
	map_[1] = &Harl::info;
	map_[2] = &Harl::warning;
	map_[3] = &Harl::error;
	levels_[0] = "DEBUG";
	levels_[1] = "INFO";
	levels_[2] = "WARNING";
	levels_[3] = "ERROR";
}

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (levels_[i] == level)
			return ((this->*map_[i])());
	}
	std::cerr
		<< "[ UNKNOWN LEVEL ]"
		<< std::endl;
}

void	Harl::debug( void )
{
	std::cout
		<< "[ DEBUG ]"
		<< std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< std::endl
		<< "I really do!"
		<< std::endl
		<< std::endl;
}

void	Harl::info( void )
{
	std::cout
		<< "[ INFO ]"
		<< std::endl
		<< "I cannot believe adding extra bacon costs more money."
		<< std::endl
		<< "You didn't put enough bacon in my burger!"
		<< std::endl
		<< "If you did, I wouldn't be asking for more!"
		<< std::endl
		<< std::endl;
}

void	Harl::warning( void )
{
	std::cout
		<< "[ WARNING ]"
		<< std::endl
		<< "I think I deserve to have some extra bacon for free."
		<< std::endl
		<< "I've been coming for years, whereas you started working here just last month."
		<< std::endl
		<< std::endl;
}

void	Harl::error( void )
{
	std::cout
		<< "[ ERROR ]"
		<< std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl
		<< std::endl;
}
