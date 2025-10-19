/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:12:53 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:39:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	len_learned_ = 0;
}

MateriaSource::MateriaSource( const MateriaSource &other )
{
	*this = other;
}

MateriaSource::~MateriaSource()
{}

MateriaSource	&MateriaSource::operator=( const MateriaSource &other )
{
	len_learned_ = other.len_learned_;
	for (size_t i = 0; i < MATERIA_SOURCE_MAX; i++)
	{
		delete learned_[i];
		learned_[i] = other.learned_[i];
	}
	return ( *this );
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for (size_t i = 0; i < len_learned_; i++)
	{
		if (learned_[i]->getType() == type)
			return ( learned_[i]->clone() );
	}
	return (0);
}

void MateriaSource::learnMateria( AMateria* materia )
{
	if (len_learned_ >= MATERIA_SOURCE_MAX)
		return ;
	learned_[len_learned_] = materia;
	len_learned_++;
}
