/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getVector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:30:13 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:30:14 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Headers.hpp"

std::vector< std::pair<std::string, std::string> > const& webserv::http::Headers::getVector( void ) const
{
	return headers_;
}
