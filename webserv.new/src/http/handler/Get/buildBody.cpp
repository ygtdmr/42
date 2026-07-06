/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildBody.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 11:27:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "../../../inc/hpp/http/handler/DirectoryListing.hpp"
#include "../../../inc/hpp/http/handler/Get.hpp"

#define READ_BUFFER_SIZE 32

void webserv::http::handler::Get::buildBody( void )
{
	static std::ifstream ifs;
	char readBuffer[READ_BUFFER_SIZE];
	if (ifs.is_open())
		ifs.open(realPath.c_str(), std::ios::binary);
	ifs.read( readBuffer, READ_BUFFER_SIZE );
	if ( ifs.gcount() )
		client->deliverData.append(readBuffer, ifs.gcount());
	else
	{
		ifs.close();
		currentState = DONE;
	}
}
