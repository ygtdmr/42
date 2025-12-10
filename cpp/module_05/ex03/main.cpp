/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:34:53 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 14:38:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{   
	Intern		someRandomIntern;
	Bureaucrat	highGradeGuy("Boss", 1);
	AForm		*formA = 0;
	AForm		*formB = 0;
	AForm		*formC = 0;
	AForm		*formD = 0;
	
	std::cout << "========== INTERN SUCCESSFUL CREATION TESTS ==========" << std::endl;

	formA = someRandomIntern.makeForm("robotomy request", "Bender");
	if ( formA )
	{
		std::cout << "-> Form created: " << *formA << std::endl;
		highGradeGuy.signForm(*formA);
		highGradeGuy.executeForm(*formA);
	}
	
	formB = someRandomIntern.makeForm("presidential pardon", "Fry");
	if ( formB )
	{
		std::cout << "-> Form created: " << *formB << std::endl;
		highGradeGuy.signForm(*formB);
		highGradeGuy.executeForm(*formB);
	}

	formC = someRandomIntern.makeForm("shrubbery creation", "Planet Express");
	if ( formC )
	{
		std::cout << "-> Form created: " << *formC << std::endl;
		highGradeGuy.signForm(*formC);
		highGradeGuy.executeForm(*formC);
	}

	std::cout << "\n========== INTERN FAILURE TESTS ==========" << std::endl;

	formD = someRandomIntern.makeForm("coffe machine form", "Kif");
	if ( !formD )
	{
		std::cout << "-> Intern successfully reported unknown form." << std::endl;
	}
	else
	{
		std::cerr << "ERROR: Intern created an unknown form!" << std::endl;
		delete formD;
	}

	delete formA;
	delete formB;
	delete formC;
	
	return (0);
}
