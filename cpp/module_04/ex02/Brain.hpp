/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:07:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define BRAIN_IDEA_LENGTH 100

class Brain
{
public:
	Brain( void );
	Brain( const Brain &other );
	~Brain();
	Brain	&operator=( const Brain &other );
private:
	std::string	ideas[BRAIN_IDEA_LENGTH];
};

#endif
