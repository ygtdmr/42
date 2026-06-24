/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:19:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/24 13:17:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_HPP
# define VALIDATION_HPP

#include <string>

bool	isValidDigit( std::string const& value );
bool	isValidIPv4( std::string const& value );
bool	isValidPath( std::string const& value, bool root = true );
const char	*getContentType( std::string const& ext );
const char	*getReasonPhrase( int statusCode );

#endif
