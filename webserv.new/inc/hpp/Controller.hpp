/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:48:40 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 08:35:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_MANAGER_CONTROLLER_HPP
#define WEBSERV_MANAGER_CONTROLLER_HPP

#include <vector>
#include "config/Server.hpp"
#include "manager/Server.hpp"

namespace webserv
{

class Controller
{
	public:
		Controller( void );
		Controller( Controller const& other );
		~Controller();
		Controller& operator=( Controller const& other );
		void		acceptConnection( size_t index ) const throw();
		void		closeConnection( size_t index, char const* reason ) const throw();
		void		setup( std::vector< config::Server > const* servers );
		void		run( void ) const throw();
		void		clear( void ) const throw();

	private:
		std::vector< manager::IManager >* connections_;
		std::vector< struct pollfd >*	  pollfds_;
};

}  // namespace webserv

#endif
