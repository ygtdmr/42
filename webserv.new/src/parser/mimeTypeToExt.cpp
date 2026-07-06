/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimeTypeToExt.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:53:03 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:51:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hpp/parser/mimeTypeToExt.hpp"

char const* webserv::parser::mimeTypeToExt( char const* mimeType )
{
	if ( mimeType == "text/html" )
		return ".html";
	else if ( mimeType == "text/css" )
		return ".css";
	else if ( mimeType == "application/javascript" || mimeType == "text/javascript" )
		return ".js";
	else if ( mimeType == "text/plain" )
		return ".txt";
	else if ( mimeType == "image/jpeg" )
		return ".jpg";
	else if ( mimeType == "image/png" )
		return ".png";
	else if ( mimeType == "image/gif" )
		return ".gif";
	else if ( mimeType == "image/bmp" )
		return ".bmp";
	else if ( mimeType == "image/x-icon" || mimeType == "image/vnd.microsoft.icon" )
		return ".ico";
	else if ( mimeType == "image/svg+xml" )
		return ".svg";
	else if ( mimeType == "application/json" )
		return ".json";
	else if ( mimeType == "application/xml" || mimeType == "text/xml" )
		return ".xml";
	else if ( mimeType == "application/pdf" )
		return ".pdf";
	else if ( mimeType == "application/zip" )
		return ".zip";
	return "";
}
