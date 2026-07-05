/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getHandler.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 10:22:58 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 12:29:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Handler.hpp"

webserv::http::handler::IHandler* webserv::parser::Handler::getHandler( void ) const
{
	return handler_;
}
