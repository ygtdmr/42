/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readErrorPageFile.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:56:10 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "http/handler/Error.hpp"
#include "http/Client.hpp"

#define READ_BUFFER_SIZE 65536

void webserv::http::handler::Error::readErrorPageFile( void ) throw()
{
	char readBuffer[READ_BUFFER_SIZE];
	if ( !fileStream_.is_open() )
		fileStream_.open( errorPagePath.c_str(), std::ios::binary );
	fileStream_.read( readBuffer, READ_BUFFER_SIZE );
	if ( fileStream_.gcount() )
		client->deliverData.append( readBuffer, fileStream_.gcount() );
	else
	{
		fileStream_.close();
		currentState = DONE;
	}
}
