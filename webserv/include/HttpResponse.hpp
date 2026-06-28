/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:15:25 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/28 11:36:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <map>
#include <string>
#include "ServerConfig.hpp"

class HttpResponse
{
	public:
		HttpResponse( void );
		HttpResponse( HttpResponse const& other );
		~HttpResponse();

		HttpResponse& operator=( HttpResponse const& other );
		void		  handleGet( LocationConfig const& locationConfig, std::string const& uriPath );
		void		  handlePost( LocationConfig const& locationConfig, std::string const& uriPath );
		void		  handleDelete( LocationConfig const& locationConfig, std::string const& uriPath );
		void		  generateErrorPage( int short code, std::map< int, std::string > const& errorPages );
		void		  generateDirectoryListing( std::string const& rootPath, std::string const& uriPath );
		std::string	  build( std::string& connection );

	private:
		char const* getReasonPhrase( int statusCode );
		char const* getContentType( std::string const& ext );

		int short							 statusCode_;
		std::string							 body_;
		std::map< std::string, std::string > headers_;
};

#endif
