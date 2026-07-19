/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getVector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 19:56:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Headers.hpp"

std::vector< std::pair<std::string, std::string> > const& webserv::http::Headers::getVector( void ) const
{
	return headers_;
}
