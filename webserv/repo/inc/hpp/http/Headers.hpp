/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:32:17 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/19 12:13:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEBSERV_HTTP_HEADERS_HPP
#define WEBSERV_HTTP_HEADERS_HPP

#include <vector>
#include <string>

namespace webserv
{

namespace http
{

class Headers
{
	public:
		Headers( void );
		Headers( std::string& str, bool skipFirstLine );
		Headers( Headers const& other );
		~Headers();

		Headers& operator=( Headers const& other );
		std::string& operator[]( std::string const& key );
		const std::string& operator[]( std::string const& key ) const;
		
		bool has( std::string const& key ) const;
		bool match( std::string const& key, std::string const& value ) const;
		void append( std::string const& key, std::string const& value );
		void set( std::string const& key, std::string const& value );
		void merge( Headers const& other );
		std::string get( std::string const& key ) const;
		std::vector< std::pair<std::string, std::string> > const& getVector( void ) const;
		std::string str( void );
	private:
		std::vector< std::pair<std::string, std::string> > headers_;
};

}  // namespace http

}  // namespace webserv

#endif
