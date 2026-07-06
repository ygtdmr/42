/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:58:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 12:57:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_MAP_HPP
#define WEBSERV_UTILS_MAP_HPP

#include <map>
#include <string>

namespace webserv
{

namespace utils
{

namespace map
{
template < typename K, typename V >
inline bool has( std::map< K, V > map, K const& key );

template < typename K, typename V >
inline bool isEq( std::map< K, V > map, K const& key, V const& value );
}  // namespace map

}  // namespace utils

}  // namespace webserv

#include "../../tpp/utils/map.tpp"

#endif
