/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 15:47:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter( void )
{}

ICharacter::ICharacter( const ICharacter &other )
{
	*this = other;
}

ICharacter::~ICharacter()
{}

ICharacter	&ICharacter::operator=( const ICharacter &other )
{
	( void ) other;
	return ( *this );
}
