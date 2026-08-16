/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:13:28 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 13:20:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string &target )
: AForm(target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
	AForm::operator=(other);
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout
		<< "* VRRRR DZZZZZ BZZZZZZ *"
		<< std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout
			<< getName()
			<< " has been robotomized successfully."
			<< std::endl;
	}
	else
	{
		std::cout
			<< "The robotomy failed on "
			<< getName()
			<< "."
			<< std::endl;
	}
}
