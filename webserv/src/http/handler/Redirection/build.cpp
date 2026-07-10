/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 09:16:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Redirection.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"

void webserv::http::handler::Redirection::build( void ) throw()
{
	headers["Location"] = uri_;
	client->deliverData = getFirstLine() + parser::mapToHeaders( headers );
	currentState		= DONE;
}
