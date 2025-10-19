/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:08:13 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/19 19:05:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource( void )
{}

IMateriaSource::IMateriaSource( const IMateriaSource &other )
{
	*this = other;
}

IMateriaSource::~IMateriaSource()
{}

IMateriaSource	&IMateriaSource::operator=( const IMateriaSource &other )
{
	( void ) other;
	return ( *this );
}
