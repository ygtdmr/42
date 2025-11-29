/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:14:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/11/29 12:24:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class	Form
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
		class	SignedAlreadyException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		Form( const std::string &name, int gradeSign, int gradeExecute );
		Form( const Form &other );
		~Form();
		Form				&operator=( const Form &other );
		const std::string	&getName( void ) const;
		bool				isSigned( void ) const;
		int					getGradeSign( void ) const;
		int					getGradeExecute( void ) const;
		void				beSigned(Bureaucrat &b);
	private:
		const std::string	name_;
		bool				isSigned_;
		int					gradeSign_;
		int					gradeExecute_;
};

std::ostream	&operator<<( std::ostream &ostream, const Form &value );

#endif
