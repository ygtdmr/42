/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isChunkedBodyDone.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 19:27:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/str.hpp"

bool webserv::parser::Request::isChunkedBodyDone( std::string const& data ) const
{
	return utils::str::has( data, "0\r\n" ) || utils::str::has( data, "0\n" );
}
