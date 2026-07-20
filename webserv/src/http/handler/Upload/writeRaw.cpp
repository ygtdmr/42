/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeRaw.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:44:34 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "http/handler/Error.hpp"
#include "http/handler/Upload.hpp"
#include "http/Client.hpp"

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
