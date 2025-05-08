/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:05:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/08 21:34:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	is_varchar(char c, size_t index)
{
	if (index == 0)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}

int	is_metachar(char *s)
{
	return (
		*s == ' ' || \
		*s == '\t' || \
		*s == '\n' || \
		*s == '<' || \
		(*s == '<' && *(s + 1) == '<') || \
		*s == '>' || \
		(*s == '>' && *(s + 1) == '>') || \
		*s == '|'
	);
}

char	*str_lrealloc(char *dest, char *src, size_t length)
{
	char	*s;
	size_t	l_s;
	size_t	i;

	i = 0;
	if (dest)
		l_s = ft_strlen(dest) + length;
	else
		l_s = length;
	s = ft_calloc(l_s + 1, sizeof(char));
	while (dest && dest[i])
	{
		s[i] = dest[i];
		i++;
	}
	while (*src && length--)
		s[i++] = *src++;
	if (dest)
		free(dest);
	return (s);
}

char	*grab_word(char **line)
{
	size_t	length;
	char	quote;

	length = 0;
	quote = 0;
	while ((*line)[length])
	{
		if ((*line)[length] == '\"' || (*line)[length] == '\'')
		{
			if (quote == 0)
				quote = (*line)[length];
			else if (quote == (*line)[length])
				quote = 0;
		}
		if (quote == 0 && is_metachar(*line + length))
			break ;
		length += 1 + ((*line)[length] == '\\');
	}
	*line += length;
	return (ft_substr(*line - length, 0, length));
}
