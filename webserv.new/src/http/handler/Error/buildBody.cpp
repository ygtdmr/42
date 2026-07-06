/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildBody.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:50:55 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 18:32:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/statusToReasonPhrase.hpp"
#include "../../../../inc/hpp/parser/mapToHeaders.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"

void webserv::http::handler::Error::buildBody( void ) throw()
{
	if ( errorPagePath.empty() )
	{
		std::stringstream	ss;
		ss << "<html>" << std::endl;
		ss << "<head><title>" << status << " " << parser::statusToReasonPhrase(status) << "</title></head>" << std::endl;
		ss << "<body>" << std::endl;
		ss << "<center><h1>" << status << " " << parser::statusToReasonPhrase(status) << "</h1></center>" << std::endl;
		ss << "</body>" << std::endl;
		ss << "</html>";
		body = ss.str();
		headers["Content-Length"] = body.size();
		client->deliverData	 = parser::mapToHeaders( headers ) + body;
		currentState = DONE;
	}
	else
		readErrorPageFile();
}
