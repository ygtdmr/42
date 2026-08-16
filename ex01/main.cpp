/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:45:56 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/15 14:49:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	try
	{
		Form formA("FormA", 50, 50);
		std::cout << formA << std::endl;

		Bureaucrat signer("Signer", 40);
		std::cout << signer << std::endl;

		signer.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form formB("FormB", 10, 10);
		std::cout << formB << std::endl;

		Bureaucrat weak("Weak", 20);
		std::cout << weak << std::endl;

		weak.signForm(formB);
		std::cout << formB << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form invalidHigh("InvalidHigh", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form invalidLow("InvalidLow", 151, 50);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
