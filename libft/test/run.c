/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tc <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:08:12 by tc                #+#    #+#             */
/*   Updated: 2024/10/12 08:23:56 by tc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../ft_memset.c"

int	main()
{
	char string[16];

	ft_memset(string, 'A', sizeof(string));

	printf("result is: %s\n", string);
	
	return 0;
}

