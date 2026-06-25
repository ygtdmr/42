/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 20:25:05 by yidemir           #+#    #+#             */
/*   Updated: 2026/06/25 18:55:28 by yidemir          ###   ########.fr       */
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
		Response			&operator=( Response const& other );
		std::string const	&process( void );

		short int				statusCode;
	private:
		void					processHeader( size_t cl, std::string const& ext );
		int						processError( int statusCode );
		int						processRoute( void );
		int						processDirectoryList( std::string const& dirPath );
		LocationConfig const	*findLocation( std::string const& path );

		Client					&client_;
		std::string				*sendData_;
};

#endif
