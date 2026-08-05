/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 17:16:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_CONV_HPP
#define WEBSERV_UTILS_CONV_HPP

#include <sstream>

namespace webserv
{

namespace utils
{

namespace conv
{
template < typename T >
inline T strTo( std::string const& str );

template < typename T >
inline std::string toStr( T const& value );

}  // namespace conv

}  // namespace utils

}  // namespace webserv

#include "../../tpp/utils/conv.tpp"

#endif
