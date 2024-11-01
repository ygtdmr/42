/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:10:27 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/29 10:35:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlent(const char *s, char const *set)
{
	char const	*fset;
	int			length;

	length = 0;
	fset = set;
	while (*s++ && *s != *set++)
	{
		length++;
		set = fset;
	}
	return (length);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	flen;

	flen = len;
	if (c > 255)
		c = 0;
	while (len--)
		*((char *)b++) = c;
	return (b - flen);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	max;

	max = SIZE_MAX;
	if ((count >= max && size > 0) || (size >= max && count > 0))
		return (0);
	max = INT_MIN;
	if ((count >= max && size > 0) || (size >= max && count > 0))
		return (0);
	max = INT_MAX;
	if ((count >= max && size > 0) || (size >= max && count > 0))
		return (0);
	p = malloc(count * size);
	if (p)
		ft_memset(p, 0, count * size);
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*fset;
	char		*fcs;
	char		*cs;
	int			t;

	if (!s1 || !set)
		return (0);
	cs = ft_calloc((ft_strlent(s1, set) + 1), sizeof(char));
	if (!cs)
		return (0);
	fset = set;
	fcs = cs;
	while (*s1++)
	{
		t = 0;
		set = fset;
		while (*set)
		{
			if (*(s1 - 1) == *set++)
				t = 1;
		}
		if (!t)
			*cs++ = *(s1 - 1);
	}
	return (fcs);
}

int	main(void)
{
	printf("result=%s\n", ft_strtrim("Hello World!", "ol"));
	return (0);
}
