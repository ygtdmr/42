/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseBody.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:33:02 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 14:41:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Request.hpp"
#include "../../../inc/hpp/utils/conv.hpp"

void webserv::parser::Request::parseBody( void )
{
	request->body += *receiveData;
	size_t contentLength( utils::conv::strTo< size_t >( request->headers["Content-Length"] ) );
	bool   isBodyDone( request->body.size() >= contentLength );
	if ( isBodyDone )
		currentState = DONE;
}
