/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:16:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
public:
	AMateria( void );
	AMateria( const AMateria &other );
	AMateria( std::string const &type );
	virtual ~AMateria();
	AMateria			&operator=( const AMateria &other );
	std::string const	&getType( void ) const;
	virtual AMateria	*clone( void ) const = 0;
	virtual void		use( ICharacter &target );
protected:
	std::string	type_;
};

#endif
