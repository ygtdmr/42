/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:01:41 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/18 19:56:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/Headers.hpp"

void webserv::http::Headers::append( std::string const& key, std::string const& value )
{
	headers_.push_back(std::make_pair(key, value));
}
