/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 08:43:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_IMANAGER_HPP
#define WEBSERV_HTTP_IMANAGER_HPP

#include <poll.h>

namespace webserv
{

namespace manager
{
class Manager
{
	public:
		virtual ~Manager() = 0;

		struct pollfd pollfd;
		char const*	  addr;
};
}  // namespace manager

}  // namespace webserv

#endif
