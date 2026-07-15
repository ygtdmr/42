/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeRaw.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:44:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 13:54:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "../../../../inc/hpp/http/handler/Error.hpp"
#include "../../../../inc/hpp/http/handler/Upload.hpp"
#include "../../../../inc/hpp/http/Client.hpp"

void webserv::http::handler::Upload::writeRaw( std::string const& mimeType )
{
	std::string	  fileName( generateFileName( mimeType ) );
	std::ofstream ofs( ( uploadPath_ + fileName ).c_str(), std::ios::out );
	if ( !ofs.is_open() )
		throw new Error( client, 500 );
	ofs.write( client->httpRequest.body.c_str(), client->httpRequest.body.size() );
	ofs.close();
	fileNames_.push_back( fileName );
}
