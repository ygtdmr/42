/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manager.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:58:30 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/06 18:57:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HTTP_MANAGER_HPP
#define WEBSERV_HTTP_MANAGER_HPP

#include <poll.h>

namespace webserv
{

namespace manager
{
class Manager
{
	public:
		Manager(void);
		Manager( Manager const& other );
		virtual ~Manager() = 0;
		Manager& operator=( Manager const& other );

		struct pollfd pollfd;
		char const*	  addr;
};
}  // namespace manager

}  // namespace webserv

#endif
