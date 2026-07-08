/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeBoundary.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 17:40:31 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:11:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctime>
#include <fstream>
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/parser/headersToMap.hpp"
#include "../../../../inc/hpp/utils/conv.hpp"
#include "../../../../inc/hpp/utils/str.hpp"
#include "../../../../inc/hpp/manager/Client.hpp"
#include "../../../../inc/hpp/http/handler/Upload.hpp"
#include "../../../../inc/hpp/http/handler/Error.hpp"

void webserv::http::handler::Upload::writeBoundary( std::string const& boundary )
{
	std::string startBoundary("\r\n--" + boundary);
	while (client->httpRequest.body != "--\r\n")
	{
		std::map<std::string, std::string> headers(parser::headersToMap(client->httpRequest.body));
		std::string fileName(utils::str::crop(headers["Content-Disposition"], "filename=\"", "\""));
		std::string boundaryContentType(headers["Content-Type"]);
		std::string writeFileName;
		size_t		counter(1);
		if (fileName.empty())
			fileName = generateFileName(boundaryContentType);
		writeFileName = fileName;
		while (!access((uploadPath_ + writeFileName).c_str(), F_OK))
			writeFileName = (utils::conv::toStr<size_t>(counter++) + "_" + fileName);
		fileNames_.push_back(writeFileName);
		std::string data(client->httpRequest.body.substr(0, client->httpRequest.body.find(startBoundary)));
		utils::str::skip(client->httpRequest.body, startBoundary.c_str());
		std::ofstream ofs((uploadPath_ + writeFileName).c_str(), std::ios::out);
		if (!ofs.is_open())
			throw new Error(client, 500);
		ofs.write(data.c_str(), data.size());
		ofs.close();
	}
}
