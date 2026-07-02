/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isBodyDone.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 19:32:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/conv.hpp"

bool webserv::parser::Request::isBodyDone( void ) const
{
	size_t contentLength( utils::conv::strTo< size_t >( request->headers["Content-Length"] ) );
	return request->body.size() < contentLength;
}
