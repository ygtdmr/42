/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:29:14 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 15:17:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	if (c > 255)
		c = 0;
	while (i < len)
		((char *)b)[i++] = c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	p = malloc(count * size);
	if (p)
		ft_memset(p, 0, count * size);
	return (p);
}

int	main(void)
{
	size_t	num_elements;
	int		*array;

	num_elements = 5;
	array = (int *) ft_calloc(num_elements, sizeof(int));

	printf("Array elements (initialized to zero):\n");

	while (num_elements--)
	{
		printf("array element=%d\n", *array);
		array++;
	}

	return (0);
}