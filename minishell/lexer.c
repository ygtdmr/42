/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:16:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 15:10:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expand.h"
#include "str_utils.h"

static int	is_metachar(char *s)
{
	return (*s == ' ' || \
*s == '\t' || \
*s == '\n' || \
*s == '<' || \
(*s == '<' && *(s + 1) == '<') || \
*s == '>' || \
(*s == '>' && *(s + 1) == '>') || \
*s == '|');
}

static void	quote_error(t_shell *sh, char **line)
{
	ft_putendl_fd("minishell: syntax error: Unterminated quoted string", 2);
	free(*line);
	*line = 0;
	clear_tok(&sh->token_head);
}

static char	*grab_word(t_shell *sh, char **line)
{
	char	*raw;
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
	if (quote)
		return (quote_error(sh, line), NULL);
	raw = ft_substr(*line, 0, length);
	str_lclean(line, length);
	return (raw);
}

void	lexer(t_shell *sh, char **line)
{
	while (*line)
	{
		if (str_mc(line, " ") || str_mc(line, "\t") || str_mc(line, "\n"))
			continue ;
		if (str_mc(line, "|"))
			new_tok(&sh->token_head, ft_strdup("|"), T_PIPE);
		else if (str_mc(line, "<<"))
			new_tok(&sh->token_head, ft_strdup("<<"), T_HEREDOC);
		else if (str_mc(line, ">>"))
			new_tok(&sh->token_head, ft_strdup(">>"), T_REDIR_APND);
		else if (str_mc(line, "<"))
			new_tok(&sh->token_head, ft_strdup("<"), T_REDIR_IN);
		else if (str_mc(line, ">"))
			new_tok(&sh->token_head, ft_strdup(">"), T_REDIR_OUT);
		else
			new_tok(&sh->token_head, expand(grab_word(sh, line), sh), T_WORD);
	}
}
