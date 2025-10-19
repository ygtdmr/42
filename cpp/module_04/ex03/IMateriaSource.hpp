/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:09:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:49:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
public:
	IMateriaSource( void );
	IMateriaSource( const IMateriaSource &other );
	virtual ~IMateriaSource();
	IMateriaSource		&operator=( const IMateriaSource &other );
	virtual void		learnMateria( AMateria* ) = 0;
	virtual AMateria	*createMateria( std::string const &type ) = 0;
};

#endif
