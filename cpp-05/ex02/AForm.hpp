/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:14:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/15 15:20:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class	AForm
{
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	NotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		AForm( const std::string &name, int gradeSign, int gradeExecute );
		AForm( const AForm &other );
		virtual ~AForm();
		AForm				&operator=( const AForm &other );
		const std::string	&getName( void ) const;
		bool				isSigned( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExecute( void ) const;
		void				beSigned( Bureaucrat &b );
		virtual void		execute( const Bureaucrat &executor ) const = 0;
	private:
		const std::string	name_;
		bool				isSigned_;
		const int			gradeSign_;
		const int			gradeExecute_;
};

std::ostream	&operator<<( std::ostream &ostream, const AForm &value );

#endif
