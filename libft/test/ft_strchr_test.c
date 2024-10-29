/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:32:51 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 22:44:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (c > 255)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

int	main(void)
{
	const char	*str;
	char		ch;
	char		*result;

	ch = 't';
	str = "tripouille";
	result = ft_strchr(str, 't' + 256);

	printf("Character '%c' result: %s\n, test: %i", ch, result, result == str);

	return (0);
}
