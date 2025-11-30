/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:14:53 by yidemir           #+#    #+#             */
/*   Updated: 2025/11/30 10:55:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    std::cout << "[TEST 1] Successful Form Creation and Output" << std::endl;
    try
    {
        Form f1("Temp 1", 100, 100);
        Form f2("Temp 2", 1, 1);
        
        std::cout << "-> Form 1: " << f1 << std::endl;
        std::cout << "-> Form 2: " << f2 << std::endl;
        
        Bureaucrat high("Temp 3", 1);
        Bureaucrat medium("Temp 4", 50);

        Form f3(f1);
        Form f4("Temp 5", 150, 150);
        f4 = f2;
        
        std::cout << "-> Form 3 (Copy of 1): " << f3 << std::endl;
        std::cout << "-> Form 4 (Assigned F2): " << f4 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "CAUGHT: Critical error during object creation: " << e.what() << std::endl;
    }

    std::cout << "\n[TEST 2] Form Constructor Error (Sign Grade 0)" << std::endl;
    try
    {
        Form invalidSignHigh("Bad Sign Grade", 0, 50);
        std::cout << "ERROR: Exception was NOT thrown for sign grade 0." << std::endl;
    }
    catch (const Form::GradeTooHighException& e)
    {
        std::cerr << "SUCCESSFULLY CAUGHT (GradeTooHigh): " << e.what() << std::endl;
    }

    std::cout << "\n[TEST 3] Form Constructor Error (Execute Grade 151)" << std::endl;
    try
    {
        Form invalidExecLow("Bad Exec Grade", 50, 151);
        std::cout << "ERROR: Exception was NOT thrown for exec grade 151." << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "SUCCESSFULLY CAUGHT (GradeTooLow): " << e.what() << std::endl;
    }

    std::cout << "\n[TEST 4] Successful Signing Test" << std::endl;
    try
    {
        Bureaucrat goodSigner("Temp signer", 49);
        Form goodForm("Temp form", 50, 75);
        
        std::cout << "Start: " << goodForm << std::endl;
        
        goodSigner.signForm(goodForm); 
        
        std::cout << "End: " << goodForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "CAUGHT: Unexpected error during successful signing: " << e.what() << std::endl;
    }

    std::cout << "\n[TEST 5] Failed Signing Test (GradeTooLow)" << std::endl;
    try
    {
        Bureaucrat badSigner("Temp signer", 100);
        Form demandingForm("Temp form", 50, 50);
        
        std::cout << "Start: " << demandingForm << std::endl;
        
        badSigner.signForm(demandingForm); 
        
        std::cout << "End (Should be Unsigned): " << demandingForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "CAUGHT: Unexpected error during failed signing: " << e.what() << std::endl;
    }
    return (0);
}
