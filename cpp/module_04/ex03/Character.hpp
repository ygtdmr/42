/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:38:18 by yidemir          ###   ########.fr       */
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
	~Character();
	Character					&operator=( const Character &other );
	virtual std::string const	&getName( void ) const;
	virtual void				equip( AMateria *m );
	virtual void				unequip( int idx );
	virtual void				use( int idx, ICharacter &target );
private:
	AMateria	*inventory_[CHARACTER_INV_MAX];
	int			len_inv_;
};

#endif
