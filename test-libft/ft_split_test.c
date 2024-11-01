/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:31:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/30 23:46:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (*s++)
		l++;
	return (l);
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

	p = malloc(count * size);
	if (p)
		ft_memset(p, 0, count * size);
	return (p);
}

static int	splitlen(char const *s, char c)
{
	int	l;
	int	isc;

	if (!s)
		return (0);
	l = 0;
	isc = 1;
	while (*s)
	{
		if (*s != c)
			isc = 0;
		if (*s == c && *(s + 1) != c && *(s + 1) != 0 && !isc)
		{
			isc = 1;
			l++;
		}
		s++;
	}
	return (l + 1);
}

static int	strclen(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s != c && *s++)
		l++;
	return (l);
}

static void	free_split(char **sp, int lsp)
{
	while (lsp--)
		free(sp[lsp]);
	free(sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	int		isplt;
	int		lsplt;
	int		lssplt;

	isplt = 0;
	lsplt = splitlen(s, c) + 1;
	sp = (char **) ft_calloc(lsplt, sizeof(char *));
	if (!sp)
		return (0);
	while (*s)
	{
		if (*s == c && s++)
			continue ;
		lssplt = strclen(s, c);
		sp[isplt] = ft_calloc(lssplt + 1, sizeof(char));
		if (!sp[isplt])
		{
			free_split(sp, lsplt);
			return (0);
		}
		ft_strlcpy(sp[isplt++], s, lssplt + 1);
		s += lssplt;
	}
	return (sp);
}

int	main(void)
{
	char	**sp;

	sp = ft_split("  tripouille   42  r    ", ' ');
	printf("result=%s\n", sp[1]);
	return (0);
}
