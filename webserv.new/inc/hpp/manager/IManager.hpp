/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IManager.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/03 12:55:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_IMANAGER_HPP
#define WEBSERV_HTTP_IMANAGER_HPP

#include <netinet/in.h>
#include <poll.h>

namespace webserv
{

namespace manager
{
class IManager
{
	public:
		virtual ~IManager() = 0;

		struct pollfd	   pollfd;
		struct sockaddr_in addr;
};
}  // namespace manager

}  // namespace webserv

#endif
