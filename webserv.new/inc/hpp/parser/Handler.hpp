/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 09:01:14 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 09:42:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_PARSER_HANDLER_HPP
#define WEBSERV_PARSER_HANDLER_HPP

#include "../http/Request.hpp"
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
		Handler&				operator=( Handler const& other );
		http::handler::IHandler parse( http::Request const& request ) const;
};

}  // namespace parser
}  // namespace webserv

#endif
