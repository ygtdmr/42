/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 07:01:01 by yidemir           #+#    #+#             */
/*   Updated: 2025/12/10 13:18:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( const std::string &target );
		RobotomyRequestForm( const RobotomyRequestForm &other );
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &other );
		void	execute(Bureaucrat const &executor) const;
};

#endif
