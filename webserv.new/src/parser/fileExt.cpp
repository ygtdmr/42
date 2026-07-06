/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileExt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:07:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 12:02:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/fileExt.hpp"
#include "../../inc/hpp/utils/str.hpp"

char const* webserv::parser::fileExt( std::string const& fileName )
{
	if ( utils::str::has( fileName, "." ) )
		return fileName.substr( fileName.find( "." ) + 1 ).c_str();
	return "";
}
