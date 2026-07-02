/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 18:44:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_MAP_TPP
#define WEBSERV_UTILS_MAP_TPP

#include "../../hpp/utils/map.hpp"

namespace webserv
{

namespace utils
{

namespace map
{
template < typename K, typename V >
bool has( std::map< K, V > map, K const& key )
{
	return map.find( key ) != map.end();
}

template < typename K, typename V >
bool isEq( std::map< K, V > map, K const& key, V const& value )
{
	if ( map.find( key ) == map.end() )
		return false;
	return map[key] == value;
}

}  // namespace map

}  // namespace utils

}  // namespace webserv

#endif
