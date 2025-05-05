/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_escape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:58:26 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/05 17:31:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static size_t	len_escpace(char *s)
{
	size_t	len;

	len = 0;
	while (s && *s)
	{
		s = ft_strchr(s, '\\');
		if (s)
		{	
			len++;
			s++;
			s += (*s == '\\');
		}
	}
	return (len);
}

char	*sanitize_escape(char *line)
{
	char	*fpline;
	char	*sntz;
	size_t	lsntz;
	size_t	i;

	fpline = line;
	lsntz = (ft_strlen(line) - len_escpace(line));
	sntz = malloc(lsntz + 1);
	sntz[lsntz] = 0;
	i = 0;
	while (i < lsntz)
	{
		while (*line == '\\' && *(line + 1) != '\\')
			line++;
		sntz[i++] = *line++;
	}
	free(fpline);
	return (sntz);
}
