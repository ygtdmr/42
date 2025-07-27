/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:35:57 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 15:12:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	raw_append(t_shell *sh, char **raw, char **out)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] && (is_rawchar((*raw)[length]) ||\
(last_tok_type_match(sh->token_head, T_HEREDOC) && (*raw)[length] == '$')))
		length++;
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length);
}

static void	var_append(t_shell *sh, char **raw, char **out, int in_dq)
{
	char	*var;
	char	*var_name;
	size_t	length;

	length = 0;
	var = 0;
	if (*raw && ft_strchr(*raw, '?'))
		var = ft_itoa(compile_status(sh->last_status));
	else
	{
		while (*raw && is_varchar((*raw)[length], length))
			length++;
		if (length > 0)
		{
			var_name = ft_calloc(length + 1, sizeof(char));
			ft_strlcpy(var_name, *raw, length + 1);
			var = env_get(sh->env, var_name);
			free(var_name);
		}
		else if (!*raw || **raw == ' ' || (in_dq && **raw == '\"'))
			var = "$";
		str_lclean(raw, length);
	}
	if (var)
		*out = str_lrealloc(*out, var, ft_strlen(var), str_mc(raw, "?"));
}

static void	dq_append(t_shell *sh, char **raw, char **out)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] && (*raw)[length] != '\"')
	{
		if ((*raw)[length] == '$')
		{
			*out = str_lrealloc(*out, *raw, length, 0);
			str_lclean(raw, length);
			length = 0;
			if (last_tok_type_match(sh->token_head, T_HEREDOC))
				raw_append(sh, raw, out);
			else
			{
				str_lclean(raw, 1);
				var_append(sh, raw, out, 1);
			}
		}
		else if ((*raw)[length] != '\"')
			length++;
	}
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length + ((*raw)[length] == '\"'));
}

static void	sq_append(char **raw, char **out)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] && (*raw)[length] != '\'')
		length++;
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length + ((*raw)[length] == '\''));
}

char	*expand(t_shell *sh, char *raw)
{
	char	*out;

	out = 0;
	while (raw)
	{
		if (str_mc(&raw, "\""))
			dq_append(sh, &raw, &out);
		else if (str_mc(&raw, "\'"))
			sq_append(&raw, &out);
		else if (last_tok_type_match(sh->token_head, T_HEREDOC))
			raw_append(sh, &raw, &out);
		else if (str_mc(&raw, "$"))
			var_append(sh, &raw, &out, 0);
		else if (raw)
			raw_append(sh, &raw, &out);
	}
	return (out);
}
