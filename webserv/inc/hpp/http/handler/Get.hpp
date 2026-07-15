/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/14 16:55:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_GET_HPP
#define WEBSERV_HTTP_HANDLER_GET_HPP

#include <fstream>
#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Get : public Handler
{
	public:
		Get( Client* client );
		Get( Get const& other );
		virtual ~Get();
		Get& operator=( Get const& other );
		void build( void );
		Handler* clone( http::Client* client );
		void buildHeaders( void );
		void buildBody( void );

	private:
		std::ifstream fileStream_;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
