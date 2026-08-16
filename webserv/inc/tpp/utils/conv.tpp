/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/19 12:59:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_CONV_TPP
#define WEBSERV_UTILS_CONV_TPP

#include "../../hpp/utils/conv.hpp"

namespace webserv
{

namespace utils
{

namespace conv
{
template < typename T >
T strTo( std::string const& str )
{
	std::stringstream ss( str );
	T				  value = T();
	ss >> value;
	return value;
}

template < typename T >
std::string toStr( T const& value )
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}
}  // namespace conv

}  // namespace utils

}  // namespace webserv

#endif
