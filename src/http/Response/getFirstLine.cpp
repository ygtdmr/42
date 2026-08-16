/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFirstLine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:42:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/Response.hpp"
#include "parser/statusToReasonPhrase.hpp"
#include "utils/conv.hpp"

std::string webserv::http::Response::getFirstLine( void ) const
{
	return version + " " + utils::conv::toStr< int short >( status ) + " " +
		   parser::statusToReasonPhrase( status ) + "\r\n";
}
