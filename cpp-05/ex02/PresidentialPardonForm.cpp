/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 05:50:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/09 07:07:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string &target )
: AForm(target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &other )
{
	AForm::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout
		<< getName()
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
