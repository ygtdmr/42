/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:33:48 by yidemir           #+#    #+#             */
/*   Updated: 2026/07/04 18:20:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hpp/Controller.hpp"
#include "unistd.h"

namespace webserv
{

void Controller::clear( void ) const
{
	for ( size_t i = 0; i < pollfds_->size(); i++ )
		close( ( pollfds_->begin() + i )->fd );
}

}  // namespace webserv
