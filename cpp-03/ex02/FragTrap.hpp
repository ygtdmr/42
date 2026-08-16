/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:59:07 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 14:48:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( const FragTrap &other );
	~FragTrap();
	FragTrap	&operator=( const FragTrap &other );

	FragTrap( const std::string &name );

	void	highFivesGuys( void );
};

#endif
