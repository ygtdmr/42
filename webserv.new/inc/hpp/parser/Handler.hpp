/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 09:01:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 09:28:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_HANDLER_HPP
#define WEBSERV_PARSER_HANDLER_HPP

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
		void					 parse( manager::Client* client );
		http::handler::IHandler* getHandler( void ) const;
};

}  // namespace parser
}  // namespace webserv

#endif
