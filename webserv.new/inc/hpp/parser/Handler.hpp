/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 09:01:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 13:12:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_HANDLER_HPP
#define WEBSERV_PARSER_HANDLER_HPP

#include "../config/Location.hpp"
#include "../http/handler/IHandler.hpp"

namespace webserv
{
namespace parser
{

class Handler
{
	public:
		Handler( void );
		Handler( Handler const& other );
		~Handler();
		Handler&				 operator=( Handler const& other );
		void					 parse( manager::Client const* client );
		http::handler::IHandler* getHandler( void ) const;

	private:
		config::Location const* matchLocation(
			std::string const& uri, std::map< std::string, config::Location > const& locations ) const;

		http::handler::IHandler* handler_;
};

}  // namespace parser
}  // namespace webserv

#endif
