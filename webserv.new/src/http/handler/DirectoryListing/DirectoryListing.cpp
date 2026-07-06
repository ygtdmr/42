/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DirectoryListing.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:01:23 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 19:11:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/hpp/http/handler/DirectoryListing.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

DirectoryListing::DirectoryListing( void )
{
	currentState = HEADERS;
}

DirectoryListing::DirectoryListing( DirectoryListing const& other ): Handler(other)
{
	*this = other;
}

DirectoryListing::~DirectoryListing() {}

DirectoryListing& DirectoryListing::operator=( DirectoryListing const& other )
{
	(void) other;
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
