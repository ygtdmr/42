/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extToMimeType.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:53:28 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 22:00:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/extToMimeType.hpp"

char const* webserv::parser::extToMimeType( char const* ext )
{
	if ( ext == ".html" || ext == ".htm" )
		return "text/html";
	else if ( ext == ".css" )
		return "text/css";
	else if ( ext == ".js" )
		return "application/javascript";
	else if ( ext == ".txt" )
		return "text/plain";
	else if ( ext == ".jpg" || ext == ".jpeg" )
		return "image/jpeg";
	else if ( ext == ".png" )
		return "image/png";
	else if ( ext == ".gif" )
		return "image/gif";
	else if ( ext == ".bmp" )
		return "image/bmp";
	else if ( ext == ".ico" )
		return "image/x-icon";
	else if ( ext == ".svg" )
		return "image/svg+xml";
	else if ( ext == ".json" )
		return "application/json";
	else if ( ext == ".xml" )
		return "application/xml";
	else if ( ext == ".pdf" )
		return "application/pdf";
	else if ( ext == ".zip" )
		return "application/zip";
	return "application/octet-stream";
}
