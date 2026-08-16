/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:46:21 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/15 15:12:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main( void )
{
std::srand(std::time(0));

	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm *rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		boss.signForm(*rrf);
		for (size_t i = 0; i < 8; i++)
			boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << std::endl;

	AForm *scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (scf)
	{
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << std::endl;

	AForm *ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (ppf)
	{
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << std::endl;

	AForm *unknown;
	unknown = someRandomIntern.makeForm("unknown form", "Nowhere");
	if (unknown)
	{
		delete unknown;
	}

	return (0);
}
