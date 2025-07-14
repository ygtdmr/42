/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:16:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 13:10:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_bonus.h"
#include "expand_bonus.h"
#include "str_utils_bonus.h"

static int	is_metachar(char *s)
{
	return (*s == ' ' || \
*s == '\t' || \
*s == '\n' || \
*s == '<' || \
(*s == '<' && *(s + 1) == '<') || \
*s == '>' || \
(*s == '>' && *(s + 1) == '>') || \
(*s == '|' && *(s + 1) == '|') || \
(*s == '&' && *(s + 1) == '&') ||
*s == '|');
}

static void	*syntax_error(t_shell *sh, char **line, char *type)
{
	ft_putstr_fd("minishell: syntax error: ", 2);
	ft_putendl_fd(type, 2);
	free(*line);
	*line = 0;
	clear_tok(&sh->token_head);
	sh->last_status = 2 << 8;
	return (0);
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
		return (syntax_error(sh, line, "Unterminated quoted string"));
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
		if (str_mc(line, "||"))
			new_tok(&sh->token_head, ft_strdup("||"), T_OPERATOR_OR);
		else if (str_mc(line, "&&"))
			new_tok(&sh->token_head, ft_strdup("&&"), T_OPERATOR_AND);
		else if (str_mc(line, "|"))
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
			new_tok(&sh->token_head, expand(sh, grab_word(sh, line)), T_WORD);
	}
}
