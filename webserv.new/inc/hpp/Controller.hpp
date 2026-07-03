/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controller.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:48:40 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/03 12:43:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_MANAGER_CONTROLLER_HPP
#define WEBSERV_MANAGER_CONTROLLER_HPP

#include <vector>
#include "config/Server.hpp"
#include "manager/IManager.hpp"

namespace webserv
{

class Controller
{
	public:
		Controller( void );
		Controller( Controller const& other );
		~Controller();
		Controller& operator=( Controller const& other );
		void		closeConnection( manager::IManager const& manager ) throw();
		void		setup( std::vector< config::Server > const* servers );
		void		runPoll() const throw();

	private:
		std::vector< manager::IManager > connections_;
};

}  // namespace webserv

#endif
