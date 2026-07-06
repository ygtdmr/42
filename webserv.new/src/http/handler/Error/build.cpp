/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:00:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Error.hpp"

void webserv::http::handler::Error::build( void ) throw()
{
	if ( currentState == HEADERS )
		buildHeaders();
	if ( currentState == BODY )
		buildHeaders();
}
