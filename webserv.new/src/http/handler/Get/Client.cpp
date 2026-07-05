/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 21:00:32 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/05 08:42:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/hpp/http/handler/Get.hpp"

namespace webserv
{
namespace http
{

namespace handler
{

Get::Get( void ) {}

Get::Get( Get const& other )
{
	*this = other;
}

Get::~Get() {}

Get& Get::operator=( Get const& other )
{
	return *this;
}

}  // namespace handler

}  // namespace http

}  // namespace webserv
