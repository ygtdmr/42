/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:31:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/29 13:27:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// check this func
int	ft_strlenc(char const *s, char c, int i)
{
	int	l;
	int	ic;

	l = 0;
	ic = 0;
	while (*s)
	{
		if (*s == c)
			ic++;
		if (*s++ != c && ic == i)
			l++;
	}
	return (l);
}

int	ft_clen(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s)
	{
		if (*s++ == c)
			l++;
	}
	return (l);
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

char	**ft_split(char const *s, char c)
{
	char	**sp;
	int		ic;
	int		lssp;

	if (!s)
		return (0);
	sp = ft_calloc(ft_clen(s, c) + 1, sizeof(char));
	ic = 0;
	while (*s)
	{
		if (sp[ic] == 0)
		{
			lssp = ft_strlenc(s, c, ic);
			sp[ic] = ft_calloc(lssp, sizeof(char));
			printf("lssp=%i", lssp);
		}
		if (*s != c)
			*(sp[ic]++) = *s;
		else
		{
			sp[ic] -= lssp;
			ic += 1;
		}
		s++;
	}
	return (sp);
}

int	main(void)
{
	printf("result=%s\n", ft_split("Hello World!", ' ')[1]);
	return (0);
}
