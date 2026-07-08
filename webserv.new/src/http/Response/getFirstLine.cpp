/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getFirstLine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 12:42:54 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 16:44:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Response.hpp"
#include "../../../inc/hpp/parser/statusToReasonPhrase.hpp"
#include "../../../inc/hpp/utils/conv.hpp"

std::string webserv::http::Response::getFirstLine( void ) const
{
	return version + " " + utils::conv::toStr< int short >( status ) + " " +
		   parser::statusToReasonPhrase( status ) + "\r\n";
}
