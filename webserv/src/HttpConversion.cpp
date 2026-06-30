/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:09:49 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/30 12:08:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HttpConversion.hpp"

char const* getReasonPhrase( int statusCode )
{
	switch ( statusCode )
	{
		case 100:
			return "Continue";
		case 101:
			return "Switching Protocols";
		case 102:
			return "Processing";
		case 103:
			return "Early Hints";

		case 200:
			return "OK";
		case 201:
			return "Created";
		case 202:
			return "Accepted";
		case 203:
			return "Non-Authoritative Information";
		case 204:
			return "No Content";
		case 205:
			return "Reset Content";
		case 206:
			return "Partial Content";
		case 207:
			return "Multi-Status";
		case 208:
			return "Already Reported";
		case 226:
			return "IM Used";

		case 300:
			return "Multiple Choices";
		case 301:
			return "Moved Permanently";
		case 302:
			return "Found";
		case 303:
			return "See Other";
		case 304:
			return "Not Modified";
		case 305:
			return "Use Proxy";
		case 306:
			return "Switch Proxy";
		case 307:
			return "Temporary Redirect";
		case 308:
			return "Permanent Redirect";

		case 400:
			return "Bad Request";
		case 401:
			return "Unauthorized";
		case 402:
			return "Payment Required";
		case 403:
			return "Forbidden";
		case 404:
			return "Not Found";
		case 405:
			return "Method Not Allowed";
		case 406:
			return "Not Acceptable";
		case 407:
			return "Proxy Authentication Required";
		case 408:
			return "Request Timeout";
		case 409:
			return "Conflict";
		case 410:
			return "Gone";
		case 411:
			return "Length Required";
		case 412:
			return "Precondition Failed";
		case 413:
			return "Content Too Large";
		case 414:
			return "URI Too Long";
		case 415:
			return "Unsupported Media Type";
		case 416:
			return "Range Not Satisfiable";
		case 417:
			return "Expectation Failed";
		case 418:
			return "I'm a teapot";
		case 421:
			return "Misdirected Request";
		case 422:
			return "Unprocessable Content";
		case 423:
			return "Locked";
		case 424:
			return "Failed Dependency";
		case 425:
			return "Too Early";
		case 426:
			return "Upgrade Required";
		case 428:
			return "Precondition Required";
		case 429:
			return "Too Many Requests";
		case 431:
			return "Request Header Fields Too Large";
		case 451:
			return "Unavailable For Legal Reasons";

		case 500:
			return "Internal Server Error";
		case 501:
			return "Not Implemented";
		case 502:
			return "Bad Gateway";
		case 503:
			return "Service Unavailable";
		case 504:
			return "Gateway Timeout";
		case 505:
			return "HTTP Version Not Supported";
		case 506:
			return "Variant Also Negotiates";
		case 507:
			return "Insufficient Storage";
		case 508:
			return "Loop Detected";
		case 510:
			return "Not Extended";
		case 511:
			return "Network Authentication Required";
	}

	return ( "Unassigned" );
}

char const* getContentType( std::string const& ext )
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

#include <string>

char const* getExtension( std::string const& mimeType )
{
    if ( mimeType == "text/html" )
        return ".html";
    else if ( mimeType == "text/css" )
        return ".css";
    else if ( mimeType == "application/javascript" || mimeType == "text/javascript" ) // Eski/alternatif tanım için bonus
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
