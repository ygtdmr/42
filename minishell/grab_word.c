/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:21:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 22:26:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expand.h"

static int	is_metachar(char *s)
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

static	size_t	read_word(t_shell *sh, char **line)
{
	char	quote;
	size_t	length;

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
		length++;
	}
	return (length);
}

char	*grab_word(t_shell *sh, char **line)
{
	char	*raw;
	size_t	length;

	length = read_word(sh, line);
	raw = ft_substr(*line, 0, length);
	str_lclean(line, length);
	return (raw);
}
