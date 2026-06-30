/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:15:25 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/29 12:11:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <map>
#include <string>
#include "HttpRequest.hpp"
#include "ServerConfig.hpp"

class HttpResponse
{
	public:
		HttpResponse( void );
		HttpResponse( HttpResponse const& other );
		~HttpResponse();

		HttpResponse& operator=( HttpResponse const& other );
		void		  handleGet( Location const& location, std::string const& uriPath );
		void		  handleDelete( Location const& location, std::string const& uriPath );
		void		  handlePost( Location const& location, HttpRequest const& httpRequest );
		void		  generateErrorPage( int short code, std::map< int, std::string > const& errorPages );
		void		  generateDirectoryListing( std::string const& rootPath, std::string const& uriPath );
		void		  generateRedirect( std::pair< int short, std::string > const& redirect );
		std::string	  build( std::string const& version, std::string& connection );

		int short statusCode;

	private:
		std::string							 body_;
		std::map< std::string, std::string > headers_;
};

#endif
