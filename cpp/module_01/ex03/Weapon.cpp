/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:03:34 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/07 14:21:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void )
{}

Weapon::Weapon( const std::string &type )
{
	type_ = type;
}

const std::string	&Weapon::getType( void ) const
{
	return (type_);
}

void	Weapon::setType( const std::string &type )
{
	type_ = type;
}
