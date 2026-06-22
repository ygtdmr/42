/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 20:25:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/21 20:30:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
# define RESPONSE_HPP

#include "Client.hpp"

class Response
{
	public:
		Response( Client& client );
		Response( Response const& other );
		~Response();
		Response	&operator=( Response const& other );
		std::string process( void ) const;
};

#endif
