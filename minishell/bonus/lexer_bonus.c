/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:16:23 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/11 08:27:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	is_metachar(char *s)
{
	return (*s == ' ' || \
*s == '\t' || \
*s == '\n' || \
*s == '<' || \
(*s == '<' && *(s + 1) == '<') || \
*s == '>' || \
(*s == '>' && *(s + 1) == '>') || \
(*s == '&' && *(s + 1) == '&') || \
(*s == '|' && *(s + 1) == '|') || \
*s == '|' || \
*s == '(' || \
*s == ')');
}

static void	*quote_error(t_shell *sh, char **line)
{
	ft_putendl_fd("minishell: syntax error: Unterminated quoted string", 2);
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
		return (quote_error(sh, line));
	raw = ft_substr(*line, 0, length);
	str_lclean(line, length);
	return (raw);
}

static void	new_tok_word(t_shell *sh, char **line)
{
	char	*raw_word;
	t_token	*new;

	sh->i_wc = 0;
	sh->len_wc = 0;
	raw_word = grab_word(sh, line);
	new_tok(&sh->token_head, expand(sh, ft_strdup(raw_word)), T_WORD);
	new = lst_tok(sh->token_head);
	new->raw_word = raw_word;
	new->i_wc = sh->i_wc;
	new->len_wc = sh->len_wc;
}

void	lexer(t_shell *sh, char **line)
{
	while (*line && !str_mc(line, "\n"))
	{
		if (str_mc(line, " ") || str_mc(line, "\t") || op_mc(sh, line))
			continue ;
		if (str_mc(line, "|"))
			new_tok(&sh->token_head, ft_strdup("|"), T_PIPE);
		else if (str_mc(line, "("))
			new_tok(&sh->token_head, ft_strdup("("), T_SUB_OPEN);
		else if (str_mc(line, ")"))
			new_tok(&sh->token_head, ft_strdup(")"), T_SUB_CLOSE);
		else if (str_mc(line, "<<"))
			new_tok(&sh->token_head, ft_strdup("<<"), T_HEREDOC);
		else if (str_mc(line, ">>"))
			new_tok(&sh->token_head, ft_strdup(">>"), T_REDIR_APND);
		else if (str_mc(line, "<"))
			new_tok(&sh->token_head, ft_strdup("<"), T_REDIR_IN);
		else if (str_mc(line, ">|") || str_mc(line, ">"))
			new_tok(&sh->token_head, ft_strdup(">"), T_REDIR_OUT);
		else if (str_mc(line, "2>"))
			new_tok(&sh->token_head, ft_strdup("2>"), T_REDIR_ERR);
		else
			new_tok_word(sh, line);
	}
}
