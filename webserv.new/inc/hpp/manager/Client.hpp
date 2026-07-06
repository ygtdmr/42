/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:44:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_MANAGER_CLIENT_HPP
#define WEBSERV_MANAGER_CLIENT_HPP

#include "Manager.hpp"
#include "Server.hpp"
#include "http/Request.hpp"
#include "http/handler/Handler.hpp"
#include "parser/Request.hpp"

namespace webserv
{

namespace manager
{
class Client : public Manager
{
	public:
		Client( void );
		Client( Client const& other );
		~Client();
		Client& operator=( Client const& other );
		void	process( void );

		bool					isConnectionClose;
		Server*					server;
		std::string				receiveData;
		std::string				deliverData;
		parser::Request			parserRequest;
		http::Request			httpRequest;
		http::handler::Handler* handler;

	private:
		void receive( void );
		void deliver( void );
		void clear( void );
};
}  // namespace manager

}  // namespace webserv

#endif
