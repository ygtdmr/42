/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:10:27 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/27 10:39:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	sj = (char *) malloc((ls1 + ls2 + 1) * sizeof(char));
	if (!sj)
		return (0);
	while (*s1)
		*sj++ = *s1++;
	while (*s2)
		*sj++ = *s2++;
	*sj = 0;
	return (sj - (ls1 + ls2));
}

int	main(void)
{
	printf("result=%s\n", ft_strjoin("Hello ", "World!"));
	return (0);
}
