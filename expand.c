/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:35:57 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/07 06:38:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	raw_append(t_shell *sh, char **raw, char **out)
{
	size_t	length;

	length = 0;
	while (((*raw)[length] && \
((*raw)[length] != '\'' && (*raw)[length] != '\"' && (*raw)[length] != '$')) \
|| (lst_tok_is(sh->token_head, T_HEREDOC) && (*raw)[length] == '$'))
		length++;
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length);
}

void	var_append(t_shell *sh, char **raw, char **out, int dq)
{
	char	*var;
	char	*var_name;
	size_t	length;

	length = 0;
	var = 0;
	if (*raw && (**raw == '?'))
		var = ft_itoa(compile_status(sh->last_status));
	else
	{
		while (*raw && is_varchar(*raw, length))
			length++;
		if (length > 0)
		{
			var_name = ft_calloc(length + 1, sizeof(char));
			ft_strlcpy(var_name, *raw, length + 1);
			var = env_get(sh->env, var_name);
			free(var_name);
		}
		else if (!*raw || **raw == ' ' || **raw == '/' || (dq && **raw == '\"'))
			var = "$";
		str_lclean(raw, length);
	}
	*out = str_realloc(*out, var, (!length && str_mc(raw, "?")));
}

static void	dq_append(t_shell *sh, char **raw, char **out)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] != '\"')
	{
		if ((*raw)[length] == '\\')
			escape_append(raw, out, 1);
		else if ((*raw)[length] == '$')
		{
			if (lst_tok_is(sh->token_head, T_HEREDOC))
				length++;
			else
			{
				*out = str_lrealloc(*out, *raw, length, 0);
				str_lclean(raw, length + 1);
				length = 0;
				var_append(sh, raw, out, 1);
			}
		}
		else
			length++;
	}
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length + 1);
	tok_quote(lst_tok(sh->token_head));
}

static void	sq_append(t_shell *sh, char **raw, char **out)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] != '\'')
		length++;
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length + 1);
	tok_quote(lst_tok(sh->token_head));
}

char	*expand(t_shell *sh, char *raw)
{
	char	*out;

	out = 0;
	while (raw)
	{
		if (raw[0] == '~' && (!raw[1] || raw[1] == '/') && str_mc(&raw, "~"))
			out = str_realloc(out, env_get(sh->env, "HOME"), 0);
		else if (*raw == '\\')
			escape_append(&raw, &out, 0);
		else if (str_mc(&raw, "\""))
			dq_append(sh, &raw, &out);
		else if (str_mc(&raw, "\'"))
			sq_append(sh, &raw, &out);
		else if (lst_tok_is(sh->token_head, T_HEREDOC))
			raw_append(sh, &raw, &out);
		else if (str_mc(&raw, "$"))
			var_append_exp(sh, &raw, &out);
		else
			raw_append(sh, &raw, &out);
	}
	return (out);
}
