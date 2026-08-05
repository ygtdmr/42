/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileExt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:07:22 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/fileExt.hpp"
#include "utils/str.hpp"

std::string webserv::parser::fileExt( std::string const& fileName )
{
	if ( utils::str::has( fileName, "." ) )
		return fileName.substr( fileName.find_last_of( "." ) );
	return "";
}
