/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:12:28 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:35:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define MATERIA_SOURCE_MAX 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &other );
	virtual ~MateriaSource();
	MateriaSource		&operator=( const MateriaSource &other );
	virtual void		learnMateria( AMateria* );
	virtual AMateria	*createMateria( std::string const &type );
private:
	AMateria	*learned_[MATERIA_SOURCE_MAX];
	int			len_learned_;
};

#endif
