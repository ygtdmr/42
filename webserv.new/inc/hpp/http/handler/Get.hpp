/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 12:44:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_GET_HPP
#define WEBSERV_HTTP_HANDLER_GET_HPP

#include "IHandler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Get : public IHandler
{
	public:
		Get( void );
		Get( Get const& other );
		virtual ~Get();
		Get& operator=( Get const& other );
		void buildHeaders( void );
		void buildBody( void );

		config::Location location;
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
