/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 20:25:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/24 13:19:20 by yidemir          ###   ########.fr       */
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
		std::string const	&process( void );
	private:
		void				processError( int statusCode );
		int					processLocation( LocationConfig const& location );

		Client				&client_;
		std::string			*sendData_;
};

#endif
