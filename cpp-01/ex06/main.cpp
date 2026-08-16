/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:56:03 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/10 09:43:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main( int argc, char **argv )
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr
			<< "usage: ./harlFilter <level>"
			<< std::endl;
		return (1);
	}
	harl.complain(argv[1]);
}
