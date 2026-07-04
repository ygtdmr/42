/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 09:57:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_MANAGER_CLIENT_HPP
#define WEBSERV_MANAGER_CLIENT_HPP

#include "IManager.hpp"
#include "Server.hpp"
#include "http/Request.hpp"
#include "http/handler/IHandler.hpp"
#include "parser/Request.hpp"

namespace webserv
{

namespace manager
{
class Client : public IManager
{
	public:
		Client( void );
		Client( Client const& other );
		~Client();
		Client& operator=( Client const& other );
		void	receive( void );
		void	deliver( void );
		void	process( void );
		void	clear( void );

		bool			isConnectionClose;
		Server*			server;
		std::string		receiveData;
		std::string		deliverData;
		parser::Request parserRequest;
		http::Request	httpRequest;
		http::Response	httpResponse;
};
}  // namespace manager

}  // namespace webserv

#endif
