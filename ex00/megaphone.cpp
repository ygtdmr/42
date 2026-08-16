/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 08:25:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/10/06 06:52:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void strtoupper( char *dest )
{
	while (*dest)
	{
		*dest = std::toupper(*dest);
		dest++;
	}
}

int	main( int argc, char **argv )
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		strtoupper(argv[i]);
		std::cout << argv[i];
		if (++i < argc)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
