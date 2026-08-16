/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:59:07 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 14:38:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AForm.hpp"

class	Intern
{
	public:
		Intern( void );
		Intern( const Intern &other );
		~Intern();
		Intern	&operator=( const Intern &other );
		AForm	*makeForm( const std::string &name, const std::string &target );
	private:
		AForm	*(Intern::*map_[3])( const std::string &target ) const;
		const char	*names_[3];
		AForm	*makePresidentialPardonForm( const std::string &target ) const;
		AForm	*makeRobotomyRequestForm( const std::string &target ) const;
		AForm	*makeShrubberyCreationForm( const std::string &target ) const;
};
