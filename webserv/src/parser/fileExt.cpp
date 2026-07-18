/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileExt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:07:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 15:28:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/fileExt.hpp"
#include "../../inc/hpp/utils/str.hpp"

std::string webserv::parser::fileExt( std::string const& fileName )
{
	if ( utils::str::has( fileName, "." ) )
		return fileName.substr( fileName.find_last_of( "." ) );
	return "";
}
