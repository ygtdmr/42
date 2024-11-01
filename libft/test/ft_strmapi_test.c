/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:31:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/31 18:25:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strdup(const char *s1)
{
	char	*sc;
	size_t	lsc;

	if (!s1)
		return (0);
	lsc = ft_strlen(s1);
	sc = malloc((lsc + 1) * sizeof(char));
	if (!sc)
		return (0);
	while (*s1)
		*sc++ = *s1++;
	*sc = 0;
	return (sc - lsc);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ns;
	int			i;

	i = 0;
	ns = ft_strdup(s);
	while (*s)
	{
		ns[i] = f(i, *s++);
		i++;
	}
	return (ns);
}

int	ft_toupper(int c)
{
	int	is_lower;

	is_lower = (c >= 97 && c <= 122);
	if (is_lower)
		return (c - 32);
	else
		return (c);
}

static char	uppercase(unsigned int index, char c)
{
	if (index % 2 == 0)
		return (ft_toupper(c));
	return (c);
}

int	main(void)
{
	printf("result=%s\n", ft_strmapi("hello world", uppercase));
	return (0);
}
