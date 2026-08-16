/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:01:01 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/09 07:07:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( const PresidentialPardonForm &other );
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &other );
		void	execute(Bureaucrat const &executor) const;
};

#endif
