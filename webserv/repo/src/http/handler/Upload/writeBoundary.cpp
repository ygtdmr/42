/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeBoundary.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:40:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctime>
#include <fstream>
#include "http/handler/Error.hpp"
#include "http/handler/Upload.hpp"
#include "http/Client.hpp"
#include "http/Headers.hpp"
#include "utils/conv.hpp"
#include "utils/str.hpp"

void webserv::http::handler::Upload::writeBoundary( std::string const& boundary )
{
	std::string startBoundary( "\r\n--" + boundary );
	while ( client->httpRequest.body != "--\r\n" )
	{
		Headers headers( Headers(client->httpRequest.body, true) );
		std::string fileName(utils::str::crop( headers.get("Content-Disposition"), "filename=\"", "\"" ));
		std::string boundaryContentType(headers.get("Content-Type"));
		std::string writeFileName;
		size_t		counter( 1 );
		if ( fileName.empty() )
			fileName = generateFileName( boundaryContentType );
		writeFileName = fileName;
		while ( !access( ( uploadPath_ + writeFileName ).c_str(), F_OK ) )
			writeFileName = ( utils::conv::toStr< size_t >( counter++ ) + "_" + fileName );
		fileNames_.push_back( writeFileName );
		std::string data(
			client->httpRequest.body.substr( 0, client->httpRequest.body.find( startBoundary ) ) );
		utils::str::skip( client->httpRequest.body, startBoundary.c_str() );
		std::ofstream ofs( ( uploadPath_ + writeFileName ).c_str(), std::ios::out );
		if ( !ofs.is_open() )
			throw new Error( client, 500 );
		ofs.write( data.c_str(), data.size() );
		ofs.close();
	}
}
