/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:35:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/05 05:35:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tok_quote(t_token *token)
{
	if (!token)
		return ;
	token->quote = 1;
}

static void	var_expand(t_shell *sh, char **out, size_t start_index)
{
	size_t	i;

	i = 0;
	(void) start_index;
	while (*out && (*out)[i])
	{
		if ((i < start_index) && ++i)
			continue ;
		else
			start_index = 0;
		if ((*out)[i] == ' ' || (*out)[i] == '\t' || (*out)[i] == '\n')
		{
			if (i)
				new_tok(&sh->token_head, str_lrealloc(0, *out, i, 0), T_WORD);
			str_lclean(out, i + 1);
			i = 0;
			continue ;
		}
		i++;
	}
}

void	var_append_exp(t_shell *sh, char **raw, char **out)
{
	size_t	start_index;

	if (*out)
		start_index = ft_strlen(*out);
	else
		start_index = 0;
	var_append(sh, raw, out, 0);
	var_expand(sh, out, start_index);
}

void	escape_append(char **raw, char **out, int dq)
{
	if (!dq || ((*raw)[1] == '$' || (*raw)[1] == '\\'))
		str_lclean(raw, 1);
	if (!*raw || (!dq && (**raw == '\'' || **raw == '\"')))
		return ;
	*out = str_lrealloc(*out, *raw, 1, 0);
	str_lclean(raw, 1);
}

int	compile_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (128 + WSTOPSIG(status));
	return (1);
}
