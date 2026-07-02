/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putDataLocation.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:48:19 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/02 10:47:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/parser/Config.hpp"
#include "../../../inc/hpp/utils/Convertion.hpp"

void webserv::parser::Config::putDataLocation( config::Location& location ) const
{
	if ( key_ == "root" )
		location.root = values_[0];
	else if ( key_ == "upload_dir" )
		location.uploadDir = values_[0];
	else if ( key_ == "index" )
		location.index = values_[0];
	else if ( key_ == "autoindex" )
		location.autoindex = ( values_[0] == "on" );
	else if ( key_ == "allow_methods" )
		location.allowMethods = values_;
	else if ( key_ == "cgi" )
		location.cgi[values_[0]] = values_[1];
	else if ( key_ == "return" )
	{
		location.redirect.first	 = utils::strTo< int short >( values_[0] );
		location.redirect.second = values_[1];
	}
	else if ( key_ == "client_max_body_size" )
	{
		char lastChar( *( values_[0].end() - 1 ) );
		bool formatMb( lastChar == 'M' || lastChar == 'm' );
		location.clientMaxBodySize = utils::strTo< size_t >( values_[0] );
		if ( formatMb )
			location.clientMaxBodySize *= 1024 * 1024;
	}
}
