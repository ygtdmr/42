/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildBody.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/07 17:26:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/Get.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"

#define READ_BUFFER_SIZE 65536

void webserv::http::handler::Get::buildBody( void )
{
	char readBuffer[READ_BUFFER_SIZE];
	if ( !fileStream_.is_open() )
		fileStream_.open( realPath.c_str(), std::ios::binary );
	fileStream_.read( readBuffer, READ_BUFFER_SIZE );
	if ( fileStream_.gcount() )
		client->deliverData.append( readBuffer, fileStream_.gcount() );
	else
	{
		fileStream_.close();
		currentState = DONE;
	}
}
