/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:21:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 11:29:15 by yidemir          ###   ########.fr       */
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

static void	next_rw(t_shell *sh, char **line, char type)
{
	char	*next_line;

	if (type == '\"')
		next_line = readline("dquote> ");
	else
		next_line = readline("quote> ");
	if (!next_line)
		return ;
	*line = str_lrealloc(*line, "\n", 1);
	*line = str_lrealloc(*line, next_line, ft_strlen(next_line));
	free(next_line);
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
		length += ((*line)[length] == '\\') + 1;
	}
	if (quote != 0)
	{
		next_rw(sh, line, quote);
		return (read_word(sh, line));
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
