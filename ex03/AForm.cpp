/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:20:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/15 14:52:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ( "AForm Exception: Grade is too high" );
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ( "AForm Exception: Grade is too low" );
}

const char	*AForm::NotSignedException::what() const throw()
{
	return ( "AForm Exception: Form is not signed" );
}

AForm::AForm( const std::string &name, int gradeSign, int gradeExecute )
: name_( name ), gradeSign_( gradeSign ), gradeExecute_( gradeExecute )
{
	if ( gradeSign > GRADE_MIN )
		throw GradeTooLowException();
	if ( gradeSign < GRADE_MAX )
		throw GradeTooHighException();
	if ( gradeExecute > GRADE_MIN )
		throw GradeTooLowException();
	if ( gradeExecute < GRADE_MAX )
		throw GradeTooHighException();
	isSigned_ = false;
}

AForm::AForm( const AForm &other )
: name_( other.name_ ), gradeSign_( other.gradeSign_ ), gradeExecute_( other.gradeExecute_ )
{
	*this = other;
}

AForm	&AForm::operator=( const AForm &other )
{
	if ( this != &other )
		isSigned_ = other.isSigned_;
	return ( *this );
}

AForm::~AForm()
{}

const std::string	&AForm::getName( void ) const
{
	return ( this->name_ );
}

bool	AForm::isSigned( void ) const
{
	return (isSigned_);
}

int	AForm::getGradeSign( void ) const
{
	return ( gradeSign_ );
}

int	AForm::getGradeExecute( void ) const
{
	return ( gradeExecute_ );
}

void	AForm::beSigned( Bureaucrat &b )
{
	if ( b.getGrade() <= gradeSign_ )
		isSigned_ = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::execute( const Bureaucrat &executor ) const
{
	if ( !isSigned_ )
		throw AForm::NotSignedException();
	if ( executor.getGrade() > gradeExecute_ )
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<( std::ostream &ostream, const AForm &value )
{
	std::cout
		<< value.getName()
		<< ", is signed: ";
	if (value.isSigned())
		std::cout << "yes, ";
	else
		std::cout << "no, ";
	std::cout
		<< "grade required sign: "
		<< value.getGradeSign()
		<< ", grade required execute: "
		<< value.getGradeExecute();
	return ( ostream );
}
