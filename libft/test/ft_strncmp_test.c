/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:06:14 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/24 18:24:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 > *s2)
			return (1);
		if (*s1++ < *s2++)
			return (-1);
	}
	return (0);
}

int	main(void)
{

	printf("result is: %i\n", strncmp("abc", "aac", 2));

	return (0);
}