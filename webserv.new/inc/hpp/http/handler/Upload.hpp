/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Upload.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 14:34:01 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:06:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_UPLOAD_HPP
#define WEBSERV_HTTP_HANDLER_UPLOAD_HPP

#include "Handler.hpp"
#include <vector>

namespace webserv
{

namespace http
{

namespace handler
{
class Upload : public Handler
{
	public:
		Upload( manager::Client* client );
		Upload( Upload const& other );
		virtual ~Upload();
		Upload& operator=( Upload const& other );
		void  build( void );
	private:
		void 	uploadFiles( void );
		void	writeBoundary( std::string const& boundary );
		void	writeRaw( std::string const& mimeType );
		std::string	generateFileName( std::string const& mimeType );

		std::vector<std::string>	fileNames_;
		std::string					uploadPath_;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
