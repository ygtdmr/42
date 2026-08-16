/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:46:08 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/15 15:07:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	std::srand(std::time(0));

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat executive("Executive", 40);
		Bureaucrat assistant("Assistant", 140);

		ShrubberyCreationForm shrub("Home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "--- Shrubbery Creation Test ---" << std::endl;
		assistant.signForm(shrub);
		assistant.executeForm(shrub);

		std::cout << std::endl;
		std::cout << "--- Robotomy Request Test ---" << std::endl;
		executive.signForm(robot);
		for (size_t i = 0; i < 8; i++)
			executive.executeForm(robot);

		std::cout << std::endl;
		std::cout << "--- Presidential Pardon Test ---" << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat newbie("Newbie", 150);
		RobotomyRequestForm robotFail("FailTarget");

		newbie.signForm(robotFail);
		newbie.executeForm(robotFail);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat cheater("Cheater", 1);
		PresidentialPardonForm unsignedForm("UnsignedTarget");

		cheater.executeForm(unsignedForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
