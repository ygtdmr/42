/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:32:51 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 20:54:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ls;
	char	ch;

	ls = 0;
	ch = (char) c;
	while (*s != 0)
	{
		if (*s == ch)
			ls = ((char *)s);
		s++;
	}
	if (ch == 0)
		return ((char *) s);
	return (ls);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	while (*s != 0)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == 0)
		return ((char *) s);
	return (0);
}

int	main(void)
{
	char *src = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";
	char *d1 = strchr(src, L'–');
	char *d2 = ft_strchr(src, L'–');

	printf("result: %s\n%s\n", d1, d2);

	return (0);
}
