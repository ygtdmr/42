/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:47:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 12:48:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	Bureaucrat	highGradeGuy("Boss (Grade 1)", 1);
	Bureaucrat	mediumGradeGuy("Manager (Grade 40)", 40);
	Bureaucrat	lowGradeGuy("Newbie (Grade 140)", 140);
	Bureaucrat	pSigner("Pardon Signer (Grade 25)", 25);
	Bureaucrat	rSigner("Robotomy Signer (Grade 72)", 72);
	Bureaucrat	sSigner("Shrubbery Signer (Grade 145)", 145);

	PresidentialPardonForm	formP("Target_Pardon");
	RobotomyRequestForm		formR("Target_Robot");
	ShrubberyCreationForm	formS("Target_Shrub");
	
	std::cout << "\n[TEST 1] Attempt to sign all forms (Polymorphism)" << std::endl;
	pSigner.signForm(formP);
	rSigner.signForm(formR);
	sSigner.signForm(formS);

	std::cout << "\n[TEST 2] Failed Signing Test (Low Grade)" << std::endl;
	RobotomyRequestForm		formR2("Target_Fail_Sign");
	lowGradeGuy.signForm(formR2);
	
	std::cout << "========== EXECUTION TESTS ==========" << std::endl;

	std::cout << "\n[TEST 3] Execution Failure: Not Signed" << std::endl;
	ShrubberyCreationForm	formS2("Target_Fail_Unsigned");
	highGradeGuy.executeForm(formS2);

	std::cout << "\n[TEST 4] Execution Failure: Grade Too Low" << std::endl;

	mediumGradeGuy.executeForm(formR);
	lowGradeGuy.executeForm(formR);

	std::cout << "\n[TEST 5] PresidentialPardonForm Execution (Exec Grade 5)" << std::endl;
	highGradeGuy.executeForm(formP);

	std::cout << "\n[TEST 6] RobotomyRequestForm Execution (Exec Grade 45)" << std::endl;
	mediumGradeGuy.executeForm(formR);
	highGradeGuy.executeForm(formR);
	highGradeGuy.executeForm(formR); 
	highGradeGuy.executeForm(formR); 

	std::cout << "\n[TEST 7] ShrubberyCreationForm Execution (Exec Grade 137)" << std::endl;

	lowGradeGuy.executeForm(formS);
	mediumGradeGuy.executeForm(formS);
	
	return (0);
}