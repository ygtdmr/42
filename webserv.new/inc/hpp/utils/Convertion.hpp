/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:52:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_CONVERTION_HPP
#define WEBSERV_UTILS_CONVERTION_HPP

#include <sstream>

namespace webserv
{

namespace utils
{

template < typename T >
inline T strTo( std::string const& str );

template < typename T >
inline std::string toStr( T const& value );

}  // namespace utils

}  // namespace webserv

#include "../../tpp/utils/Convertion.tpp"

#endif
