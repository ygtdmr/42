/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateFileName.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:40:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:00:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctime>
#include "../../../../inc/hpp/parser/mimeTypeToExt.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"
#include "../../../../inc/hpp/http/handler/Upload.hpp"

std::string webserv::http::handler::Upload::generateFileName( std::string const& mimeType )
{
	size_t		counter(0);
	std::string	filename(utils::conv::toStr<time_t>(std::time(0)) + parser::mimeTypeToExt(mimeType));
	while (!access((uploadPath_ + filename).c_str(), F_OK))
		filename = (utils::conv::toStr<size_t>(++counter) + "_" + filename);
	return filename;
}
