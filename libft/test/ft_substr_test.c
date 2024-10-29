/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:54:26 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 22:42:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	flen;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	flen = len;
	ss = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ss)
		return (0);
	s += start;
	while (*s && len)
	{
		*ss++ = *s++;
		len--;
	}
	return (ss - (flen - len));
}

int	main(void)
{
	printf("result=%s\n", ft_substr("Hello World!", 6, 3));
	return (0);
}
