/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:19:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/25 19:51:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_HPP
# define VALIDATION_HPP

#include <string>
#include "Response.hpp"

bool		isValidDigit( std::string const& value );
bool		isValidIPv4( std::string const& value );
bool		isValidPath( std::string const& value, bool root = true );
std::string	strTrim( std::string const& str );
const char	*getContentType( std::string const& ext );
const char	*getReasonPhrase( int statusCode );

#endif
