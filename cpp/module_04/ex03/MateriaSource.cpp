/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:12:53 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:50:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (size_t i = 0; i < MATERIA_SOURCE_MAX; i++)
		learned_[i] = 0;
}

MateriaSource::MateriaSource( const MateriaSource &other ) : IMateriaSource(other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MATERIA_SOURCE_MAX; i++)
		delete learned_[i];
}

MateriaSource	&MateriaSource::operator=( const MateriaSource &other )
{
	if (this != &other)
	{
		for (int i = 0; i < MATERIA_SOURCE_MAX; ++i)
		{
			delete learned_[i];
			if (other.learned_[i])
				learned_[i] = other.learned_[i]->clone();
			else
				learned_[i] = 0;
		}
	}
	return ( *this );
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (int i = 0; i < MATERIA_SOURCE_MAX; i++)
	{
		if (learned_[i] && learned_[i]->getType() == type)
			return ( learned_[i]->clone() );
	}
	return (0);
}

void MateriaSource::learnMateria( AMateria* materia )
{
	if (!materia)
		return ;
	for (int i = 0; i < MATERIA_SOURCE_MAX; i++)
	{
		if (!learned_[i]) {
			learned_[i] = materia;
			return ;
		}
	}
	delete materia;
}
