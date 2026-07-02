/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertion.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:46:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:45:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_UTILS_CONVERTION_TPP
#define WEBSERV_UTILS_CONVERTION_TPP

#include "../../hpp/utils/Convertion.hpp"

namespace webserv
{

namespace utils
{

template < typename T >
T strTo( std::string const& str )
{
	std::stringstream ss( str );
	T				  value;
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

}  // namespace utils

}  // namespace webserv

#endif
