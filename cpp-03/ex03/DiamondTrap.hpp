/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:09:07 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/16 16:37:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap( void );
	DiamondTrap( const DiamondTrap &other );
	~DiamondTrap();
	DiamondTrap	&operator=( const DiamondTrap &other );

	DiamondTrap( const std::string &name );
	void	whoAmI( void );
	using	ScavTrap::attack;
private:
	std::string	name_;
};

#endif
