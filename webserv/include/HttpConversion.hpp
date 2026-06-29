/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:09:12 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 10:10:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_CONVERSION_HPP
#define HTTP_CONVERSION_HPP

#include <string>

char const* getReasonPhrase( int statusCode );
char const* getContentType( std::string const& ext );

#endif