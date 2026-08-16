/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:59:07 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 15:26:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( const ScavTrap &other );
	~ScavTrap();
	ScavTrap	&operator=( const ScavTrap &other );

	ScavTrap( const std::string &name );
	
	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif
