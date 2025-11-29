/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 06:41:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/11/29 12:09:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << "[TEST 1] Successful Object Creation and Output Operator Test" << std::endl;

	Bureaucrat a("A", 75);
	Bureaucrat b("B", 150);
	Bureaucrat c("C", 1);
	
	std::cout << "-> A (75): " << a << std::endl;
	std::cout << "-> B (150): " << b << std::endl;
	std::cout << "-> C (1): " << c << std::endl;

	std::cout << "\n[TEST 1.1] Copy Constructor Test" << std::endl;
	Bureaucrat d(a);
	std::cout << "-> d (Copy of A): " << d << std::endl;

	std::cout << "[TEST 1.2] Assignment Operator Test" << std::endl;
	b = a; 
	std::cout << "-> B (After assignment): " << b << std::endl;


	std::cout << "\n[TEST 2] Constructor Error Test (Grade 0)" << std::endl;
	try
	{
		std::cout << "-> Attempting to create with Grade 0 (Too High)..." << std::endl;
		Bureaucrat tooHigh("Error Guy", 0);
		std::cout << "ERROR: Exception was NOT thrown for Grade 0." << std::endl;
	}
	catch ( const Bureaucrat::GradeTooHighException& e )
	{
		std::cerr << "SUCCESSFULLY CAUGHT (GradeTooHigh): " << e.what() << std::endl;
	}

	std::cout << "\n[TEST 3] Constructor Error Test (Grade 151)" << std::endl;
	try
	{
		std::cout << "-> Attempting to create with Grade 151 (Too Low)..." << std::endl;
		Bureaucrat tooLow("Another Error Guy", 151);
		std::cout << "ERROR: Exception was NOT thrown for Grade 151." << std::endl;
	}
	catch ( const Bureaucrat::GradeTooLowException& e )
	{
		std::cerr << "SUCCESSFULLY CAUGHT (GradeTooLow): " << e.what() << std::endl;
	}

	std::cout << "\n[TEST 4] Successful Grade Manipulation Test" << std::endl;
	Bureaucrat medium("Medium Guy", 100);
	std::cout << "Start: " << medium << std::endl;

	medium.upGrade(1);
	std::cout << "After upGrade(1) (99): " << medium << std::endl;

	medium.downGrade(1);
	std::cout << "After downGrade(1) (100): " << medium << std::endl;


	std::cout << "\n[TEST 5] upGrade Error Test (Exceeding Grade 1)" << std::endl;
	try
	{
		Bureaucrat tmp("Temp", 2);
		std::cout << "Start: " << tmp << std::endl;
		tmp.upGrade(1);
		std::cout << "Grade after first upGrade(1): " << tmp << std::endl;

		tmp.upGrade(1);
		std::cout << "ERROR: Exception was NOT thrown after second upGrade(1)." << std::endl;
	}
	catch ( const Bureaucrat::GradeTooHighException& e )
	{
		std::cerr << "SUCCESSFULLY CAUGHT (GradeTooHigh): " << e.what() << std::endl;
	}

	std::cout << "\n[TEST 6] downGrade Error Test (Exceeding Grade 150)" << std::endl;
	try
	{
		Bureaucrat tmp("Temp", 149);
		std::cout << "Start: " << tmp << std::endl;
		tmp.downGrade(1);
		std::cout << "Grade after first downGrade(1): " << tmp << std::endl;

		tmp.downGrade(1);
		std::cout << "ERROR: Exception was NOT thrown after second downGrade(1)." << std::endl;
	}
	catch ( const std::exception& e )
	{
		std::cerr << "SUCCESSFULLY CAUGHT (GradeTooLow): " << e.what() << std::endl;
	}
	return (0);
}
