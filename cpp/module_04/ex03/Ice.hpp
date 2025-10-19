/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:18:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( const Ice &other );
	virtual ~Ice();
	Ice					&operator=( const Ice &other );
	virtual AMateria	*clone( void ) const;
	virtual void		use( ICharacter &target );
};

#endif
