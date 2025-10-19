/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:09:55 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:09:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( const Cure &other );
	~Cure();
	Cure				&operator=( const Cure &other );
	virtual AMateria	*clone( void ) const;
	virtual void		use( ICharacter &target );
};

#endif
