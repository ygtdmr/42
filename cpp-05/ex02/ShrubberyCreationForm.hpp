/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 05:38:12 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/09 07:07:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		class	FileException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		ShrubberyCreationForm( const std::string &target );
		ShrubberyCreationForm( const ShrubberyCreationForm &other );
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other );
		void	execute(Bureaucrat const &executor) const;
};

#endif
