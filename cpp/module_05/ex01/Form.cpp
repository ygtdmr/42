/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:20:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/11/29 12:25:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char	*Form::GradeTooHighException::what() const throw()
{
	return ( "Form Exception: Grade is too high" );
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ( "Form Exception: Grade is too low" );
}

const char	*Form::SignedAlreadyException::what() const throw()
{
	return ( "Form Exception: Form already signed" );
}

Form::Form( const std::string &name, int gradeSign, int gradeExecute )
: name_(name)
{
	if ( gradeSign > GRADE_MIN )
		throw GradeTooLowException();
	if ( gradeSign < GRADE_MAX )
		throw GradeTooHighException();
	if ( gradeExecute > GRADE_MIN )
		throw GradeTooLowException();
	if ( gradeExecute < GRADE_MAX )
		throw GradeTooHighException();
	gradeSign_ = gradeSign;
	gradeExecute_ = gradeExecute;
	isSigned_ = false;
}

Form::Form(const Form &other)
: name_(other.name_)
{
	*this = other;
}

Form	&Form::operator=( const Form &other )
{
	if (this != &other)
	{
		isSigned_ = other.isSigned_;
		gradeSign_ = other.gradeSign_;
		gradeExecute_ = other.gradeExecute_;
	}
	return ( *this );
}

Form::~Form()
{}

const std::string	&Form::getName( void ) const
{
	return ( this->name_ );
}

bool	Form::isSigned( void ) const
{
	return (isSigned_);
}

int	Form::getGradeSign( void ) const
{
	return ( gradeSign_ );
}

int	Form::getGradeExecute( void ) const
{
	return ( gradeExecute_ );
}

void	Form::beSigned(Bureaucrat &b)
{
	if ( isSigned_ )
		throw Form::SignedAlreadyException();
	else if ( b.getGrade() <= gradeSign_ )
		isSigned_ = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<( std::ostream &ostream, const Form &value )
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
	return (ostream);
}
