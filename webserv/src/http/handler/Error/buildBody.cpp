/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildBody.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "http/handler/Error.hpp"
#include "http/Client.hpp"
#include "parser/statusToReasonPhrase.hpp"
#include "utils/conv.hpp"

void webserv::http::handler::Error::buildBody( void ) throw()
{
	if ( errorPagePath.empty() )
	{
		std::stringstream ss;
		ss << "<html>" << std::endl;
		ss << "<head><title>" << status << " " << parser::statusToReasonPhrase( status ) << "</title></head>"
		   << std::endl;
		ss << "<body>" << std::endl;
		ss << "<center><h1>" << status << " " << parser::statusToReasonPhrase( status ) << "</h1></center>"
		   << std::endl;
		ss << "<hr><center>webserv</center>" << std::endl;
		ss << "</body>" << std::endl;
		ss << "</html>";
		body					  = ss.str() + "\r\n";
		headers.set("Content-Length", utils::conv::toStr< size_t >( body.size()));
		client->deliverData += headers.str();
		if ( client->httpRequest.method != "HEAD" )
			client->deliverData += body;
		currentState = DONE;
	}
	else
		readErrorPageFile();
}
