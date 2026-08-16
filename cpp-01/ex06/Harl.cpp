/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 07:22:15 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/10 09:50:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{
	levels_[0] = "DEBUG";
	levels_[1] = "INFO";
	levels_[2] = "WARNING";
	levels_[3] = "ERROR";
}

void	Harl::complain( std::string level )
{
	int	i;

	i = 0;
	while (i < 4 && levels_[i] != level)
		i++;
	switch (i)
	{
	case 0:
		this->debug();
		this->info();
		this->warning();
		this->error();
		break ;
	case 1:
		this->info();
		this->warning();
		this->error();
		break ;
	case 2:
		this->warning();
		this->error();
		break ;
	case 3:
		this->error();
		break ;
	default:
		std::cerr
			<< "[ Probably complaining about insignificant problems ]"
			<< std::endl;
		break ;
	}
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
