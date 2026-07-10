/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Delete.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/08 19:40:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_HANDLER_DELETE_HPP
#define WEBSERV_HTTP_HANDLER_DELETE_HPP

#include "Handler.hpp"

namespace webserv
{

namespace http
{

namespace handler
{
class Delete : public Handler
{
	public:
		Delete( manager::Client* client );
		Delete( Delete const& other );
		virtual ~Delete();
		Delete& operator=( Delete const& other );
		void	build( void );
};
}  // namespace handler

}  // namespace http

}  // namespace webserv

#endif
