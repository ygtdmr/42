/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lsrc;
	size_t	ldst;
	size_t	ldcat;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	if (dstsize && dstsize >= ldst)
	{
		ldcat = dstsize - 1;
		if (ldcat > ldst)
			ldcat -= ldst;
		dst += ldst;
		while (*src && ldcat--)
			*dst++ = *src++;
		*dst = 0;
	}
	if (dstsize < ldst)
		return (dstsize + lsrc);
	else
		return (ldst + lsrc);
}

int	main(void)
{
	char	dest[20];
	size_t	size;

	strlcpy(dest, "Hello", 10);

	size = strlcat(dest, "abc", 8);

	printf("result=%s\nsize=%zu\n", dest, size);
}
