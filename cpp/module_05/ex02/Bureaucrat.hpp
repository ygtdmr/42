/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:14:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 13:41:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define	GRADE_MIN 150
#define	GRADE_MAX 1

class AForm;

class	Bureaucrat
{
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat( const std::string &name, int grade );
		~Bureaucrat();
		Bureaucrat			&operator=( const Bureaucrat &other );
		const std::string	&getName( void ) const;
		int					getGrade( void ) const;
		void				upGrade( int value );
		void				downGrade( int value );
		void				signForm( AForm &f );
		void				executeForm( const AForm &form ) const;
	private:
		const std::string	name_;
		int					grade_;
};

std::ostream	&operator<<( std::ostream &ostream, const Bureaucrat &value );

#endif
