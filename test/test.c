/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:23 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/17 16:22:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../get_next_line/get_next_line.h"

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

	lsc = ft_strlen(s1);
	sc = malloc((lsc + 1) * sizeof(char));
	if (!sc)
		return (0);
	while (*s1 != 0)
		*sc++ = *s1++;
	*sc = 0;
	return (sc - lsc);
}

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);

	printf("r=%s", get_next_line(fd));
	printf("r=%s", get_next_line(fd));

	return (0);
}
