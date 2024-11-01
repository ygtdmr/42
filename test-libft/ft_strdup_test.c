/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:16:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 16:31:09 by yidemir          ###   ########.fr       */
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

int	main(void)
{
	const char	*original = "Hello World!";
	char		*copy;

	copy = ft_strdup(original);

	printf("original: %s\ncopy: %s\n", original, copy);

	free(copy);

	return (0);
}
