/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:34:15 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/05 16:56:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include <stdio.h>

static size_t strclen(char *s, char c)
{
	size_t len;

	len = 0;
	while (s && *s)
	{
		s = ft_strchr(s, c);
		if (s)
		{
			len++;
			s++;
		}
	}
	return (len);
}

static char	*sanitize_escape(char *line)
{
	char	*sntz;
	size_t	lsntz;
	size_t	i;

	lsntz = (ft_strlen(line) - strclen(line, '\\'));
	sntz = malloc(lsntz + 1);
	sntz[lsntz] = 0;
	i = 0;
	while (i < lsntz)
	{
		while (*line == '\\')
			line++;
		sntz[i++] = *line++;
	}
	return (sntz);
}

int	main(void)
{
	char *s = "Test\\de\\\\\\neme\\test\\wrw";
	printf("target=%s\nsanitized=%s", s, sanitize_escape(s));
}
