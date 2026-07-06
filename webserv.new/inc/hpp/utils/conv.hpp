/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 21:48:13 by yidemir          ###   ########.fr       */
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

char const* mimeTypeToExt( char const* mimeType );

char const* extToMimeType( char const* ext );

char const* statusToReasonPhrase( int short status );

}  // namespace conv

}  // namespace utils

}  // namespace webserv

#include "../../tpp/utils/conv.tpp"

#endif
