/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readErrorPageFile.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:56:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 18:33:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"

#define READ_BUFFER_SIZE 32

void webserv::http::handler::Error::readErrorPageFile( void ) throw()
{
	static std::ifstream ifs;
	char				 readBuffer[READ_BUFFER_SIZE];
	if ( ifs.is_open() )
		ifs.open( errorPagePath.c_str(), std::ios::binary );
	ifs.read( readBuffer, READ_BUFFER_SIZE );
	if ( ifs.gcount() )
		client->deliverData.append( readBuffer, ifs.gcount() );
	else
	{
		ifs.close();
		currentState = DONE;
	}
}
