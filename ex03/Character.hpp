/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:29:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# define CHARACTER_INV_MAX 4

class Character : public ICharacter
{
public:
	Character( void );
	Character( const Character &other );
	Character( const std::string &name );
	virtual ~Character();
	Character			&operator=( const Character &other );
	std::string const	&getName( void ) const;
	void				equip( AMateria *m );
	void				unequip( int idx );
	void				use( int idx, ICharacter &target );
private:
	AMateria	*inventory_[CHARACTER_INV_MAX];
	std::string	name_;
};

#endif
