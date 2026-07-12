/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/12 07:35:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../../../../inc/hpp/http/handler/Upload.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"

void webserv::http::handler::Upload::build( void )
{
	uploadFiles();
	std::stringstream ss;
	ss << "<html>" << std::endl;
	ss << "<head><title>File Uploaded</title></head>" << std::endl;
	ss << "<body>" << std::endl;
	ss << "<h1>File(s) succesfuly uploaded</h1>" << std::endl;
	ss << "<hr><pre>" << std::endl;
	for ( size_t i = 0; i < fileNames_.size(); i++ )
		ss << "<p>" << fileNames_[i] << "</p>" << std::endl;
	ss << "</pre><hr></body>" << std::endl;
	ss << "</html>" << std::endl;
	body					  = ss.str();
	headers["Content-Type"]	  = "text/html";
	headers["Content-Length"] = utils::conv::toStr< size_t >( body.size() );
	status					  = 201;
	client->deliverData		  = getFirstLine() + parser::mapToHeaders( headers ) + body;
	currentState			  = DONE;
}
