/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:46:04 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/23 21:48:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	if (c > 255)
		c = 0;
	while (i < len)
		((char *)b)[i++] = c;
	return (b);
}

int	main(void)
{
	char	s[32];

	ft_memset(s, 'A', 32);

	printf("result is: %s\n", s);

	ft_memset(s, 'B', 4);

	printf("result is: %s\n", s);

	return (0);
}
