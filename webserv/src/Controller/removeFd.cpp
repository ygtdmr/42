/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeFd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:00:00 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/11 12:00:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../inc/hpp/Controller.hpp"

namespace webserv
{

void Controller::removeFd( int fd, size_t* posPoll ) const throw()
{
	if ( fd < 0 )
		return;
	for ( size_t i = 0; i < pollfds->size(); i++ )
	{
		if ( ( *pollfds )[i].fd == fd )
		{
			close( fd );
			pollfds->erase( pollfds->begin() + i );
			connections->erase( connections->begin() + i );
			if ( posPoll && *posPoll >= i )
				( *posPoll )--;
			break;
		}
	}
}

}  // namespace webserv
