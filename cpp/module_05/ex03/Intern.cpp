/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:01:49 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 14:47:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	map_[0] = &Intern::makePresidentialPardonForm;
	map_[1] = &Intern::makeRobotomyRequestForm;
	map_[2] = &Intern::makeShrubberyCreationForm;
	names_[0] = "presidential pardon";
	names_[1] = "robotomy request";
	names_[2] = "shrubbery creation";
}

Intern::Intern( const Intern &other )
{
	*this = other;
}

Intern::~Intern()
{}

Intern	&Intern::operator=( const Intern &other )
{
	( void ) other;
	return ( *this );
}

AForm	*Intern::makeForm( const std::string &name, const std::string &target )
{
	for (int i = 0; i < 3; i++)
	{
		if (names_[i] == name)
		{
			std::cout
				<< "Intern creates "
				<< target
				<< std::endl;
			return ( ( this->*map_[i] )( target ) ) ;
		}
	}
	std::cerr
		<< "[ UNKNOWN NAME ]"
		<< std::endl;
	return ( 0 );
}

AForm	*Intern::makePresidentialPardonForm( const std::string &target ) const
{
	return ( new PresidentialPardonForm( target ) );
}
AForm	*Intern::makeRobotomyRequestForm( const std::string &target ) const
{
	return ( new RobotomyRequestForm( target ) );
}
AForm	*Intern::makeShrubberyCreationForm( const std::string &target ) const
{
	return ( new ShrubberyCreationForm( target ) );
}
