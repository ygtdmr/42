/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 05:50:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/09 07:07:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target )
: AForm(target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	AForm::operator=(other);
	return (*this);
}

const char	*ShrubberyCreationForm::FileException::what() const throw()
{
	return ( "ShrubberyCreationForm Exception: File open or write error" );
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::fstream	file;
	std::string		outName;

	AForm::execute(executor);
	if ( file.is_open() )
		file.close();
	outName = getName() + "_shrubbery";
	file.open( outName.c_str(), std::ios_base::out );
	if ( file.fail() )
		throw ShrubberyCreationForm::FileException();
	file.write( "      *\n     ***\n    *****\n   *******\n  *********\n     |||\n     |||", 67 );
	if ( file.fail() )
		throw ShrubberyCreationForm::FileException();
}
