/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:20:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/11/29 12:10:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "Bureaucrat Exception: Grade is too high (must be >= 1)" );
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ( "Bureaucrat Exception: Grade is too low (must be <= 150)" );
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: name_(other.name_)
{
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &other )
{
	if ( this != &other )
		grade_ = other.grade_;
	return ( *this );
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: name_(name)
{
	if ( grade > GRADE_MIN )
		throw GradeTooLowException();
	else if ( grade < GRADE_MAX )
		throw GradeTooHighException();
	else
		grade_ = grade;
}

Bureaucrat::~Bureaucrat()
{}

const std::string	&Bureaucrat::getName( void ) const
{
	return ( this->name_ );
}

int	Bureaucrat::getGrade( void ) const
{
	return ( this->grade_ );
}

void	Bureaucrat::upGrade( int value )
{
	if ( ( grade_ - value ) >= GRADE_MAX  )
		grade_ -= value;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::downGrade( int value )
{
	if ( ( grade_ + value ) <= GRADE_MIN )
		grade_ += value;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned( *this );
		std::cout
			<< getName()
			<< " signed "
			<< f.getName()
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< getName()
			<< " couldn't sign "
			<< f.getName()
			<< " because "
			<< e.what()
			<< std::endl;
	}
}

std::ostream	&operator<<( std::ostream &ostream, const Bureaucrat &value )
{
	std::cout
		<< value.getName()
		<< ", bureaucrat grade "
		<< value.getGrade()
		<< ".";
	return (ostream);
}
