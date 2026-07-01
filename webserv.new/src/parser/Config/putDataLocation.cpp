/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putDataLocation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:48:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/01 12:06:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parser/Config.hpp"

void webserv::parser::Config::putDataLocation( config::Location& location ) const
{
	std::stringstream ss( *( values_.begin() ) );

	if ( key_ == "root" )
		ss >> location.root;
	else if ( key_ == "upload_dir" )
		ss >> location.uploadDir;
	else if ( key_ == "cgi_extension" )
		ss >> location.cgiExtension;
	else if ( key_ == "cgi_path" )
		ss >> location.cgiPath;
	else if ( key_ == "index" )
		ss >> location.index;
	else if ( key_ == "autoindex" )
		location.autoindex = ( ss.str() == "on" );
	else if ( key_ == "allow_methods" )
		location.allowMethods = values_;
	else if ( key_ == "return" )
	{
		ss >> location.redirect.first;
		ss.clear();
		ss.str( *( values_.end() - 1 ) );
		ss >> location.redirect.second;
	}
}
