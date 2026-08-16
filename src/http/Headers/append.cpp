/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurganci <gurganci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:29:51 by gurganci          #+#    #+#             */
/*   Updated: 2026/08/07 18:29:53 by gurganci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "http/Headers.hpp"

void webserv::http::Headers::append( std::string const& key, std::string const& value )
{
	headers_.push_back(std::make_pair(key, value));
}
