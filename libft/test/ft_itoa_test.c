/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:31:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/31 17:57:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static int	ilen(int i)
{
	int	l;

	l = 0;
	if (i < 0)
		i *= -1;
	while (i >= 10)
	{
		i /= 10;
		l++;
	}
	return (l + 1);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		ln;
	int		isn;

	if (n == -2147483648)
	{
		s = ft_calloc(12, sizeof(char));
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}

	ln = ilen(n);
	isn = n < 0;
	s = ft_calloc(ln + isn + 1, sizeof(char));
	if (isn)
	{
		n *= -1;
		*s = 45;
	}
	while (ln)
	{
		*(s + (isn + --ln)) = 48 + (n % 10);
		n /= 10;
	}
	return (s);
}

int	main(void)
{
	printf("result=%s\n", ft_itoa(-2147483648));
	return (0);
}
