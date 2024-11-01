/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:48:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 22:44:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;

	lsrc = ft_strlen(src);
	if (dstsize)
	{
		while (*src && ((dstsize--) - 1))
			*dst++ = *src++;
		*dst = 0;
	}
	return (lsrc);
}

int	main(void)
{
	char	dest[10];
	size_t	size;


	size = strlcpy(dest, "Hello World!", 0);

	printf("result=%s\nsize=%zu\n", dest, size);
}
