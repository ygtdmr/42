/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:05:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/05 17:28:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	is_metachar(char *s)
{
	return (
		*s == ' ' || \
		*s == '<' || \
		(*s == '<' && *(s + 1) == '<') || \
		*s == '>' || \
		(*s == '>' && *(s + 1) == '>') || \
		*s == '|'
	);
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
