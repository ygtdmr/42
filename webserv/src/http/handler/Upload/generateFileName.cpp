/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateFileName.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:40:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/20 12:58:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctime>
#include "http/handler/Upload.hpp"
#include "parser/mimeTypeToExt.hpp"
#include "utils/conv.hpp"

std::string webserv::http::handler::Upload::generateFileName( std::string const& mimeType )
{
	size_t		counter( 0 );
	std::string filename( utils::conv::toStr< time_t >( std::time( 0 ) ) +
						  parser::mimeTypeToExt( mimeType ) );
	while ( !access( ( uploadPath_ + filename ).c_str(), F_OK ) )
		filename = ( utils::conv::toStr< size_t >( ++counter ) + "_" + filename );
	return filename;
}
