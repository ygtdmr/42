/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:56:03 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/10 06:59:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileManager.hpp"

int	main( int argc, char **argv )
{
	FileManager	filemanager;

	if (argc != 4)
	{
		std::cerr << "missing parameter(s), usage: <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filemanager.setInOutName(argv[1], std::string(argv[1]) + ".replace");
	if (!filemanager.replace(argv[2], argv[3]))
	{
		if (errno)
			std::perror(argv[1]);
		else
			std::cerr << argv[1] << ": replace error" << std::endl;
		return (1);
	}
	return (0);
}
