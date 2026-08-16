/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 21:20:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/02/25 11:41:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{}

Serializer::Serializer( const Serializer &other )
{
	( void ) other;
}

Serializer &Serializer::operator=( const Serializer &other )
{
	( void ) other;
	return ( *this );
}

Serializer::~Serializer()
{}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data	*Serializer::deserialize( uintptr_t raw )
{
	return ( reinterpret_cast<Data *>(raw) );
}
