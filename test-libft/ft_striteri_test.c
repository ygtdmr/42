/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:31:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/31 18:43:28 by yidemir          ###   ########.fr       */
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

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		f(i, (s + i));
		i++;
	}
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

static void	uppercase(unsigned int i, char *s)
{
	if (i % 2 == 0)
		*s = ft_toupper(*s);
}

int	main(void)
{
	char	*s;

	s = ft_strdup("hello world");

	ft_striteri(s, uppercase);
	printf("result=%s\n", s);
	return (0);
}
