/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:28:54 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/24 18:45:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*bs;

	bs = (char *) s;
	if (c > 255)
		c -= 256;
	while (n--)
	{
		if (*bs == c)
			return (bs);
		bs++;
	}
	return (0);
}

int	main(void)
{
	char	str[20];

	strcpy(str, "abcdefg");

	printf("result=%s\n", (char *) ft_memchr(str, 'e' + 259, 40));
	return (0);
}
