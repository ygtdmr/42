/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:35:57 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 16:57:06 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "str_utils.h"
#include "env_utils.h"

static void	var_append(char **raw, char **out, t_shell *sh)
{
	char	*var;
	char	*var_name;
	size_t	length;

	length = 0;
	str_lclean(raw, 1);
	if (str_match(*raw, "?"))
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
		else
			var = "$";
		str_lclean(raw, length);
	}
	if (var)
		*out = str_lrealloc(*out, var, ft_strlen(var), str_mc(raw, "?"));
}

static void	dq_append(char **raw, char **out, t_shell *sh)
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
			var_append(raw, out, sh);
			if (!*raw)
				return ;
		}
		else
			length++;
	}
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length + ((*raw)[length] == '\"'));
}

static void	sq_append(char **raw, char **out, t_shell *sh)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] && (*raw)[length] != '\'')
		length++;
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length + ((*raw)[length] == '\''));
}

static void	raw_append(char **raw, char **out)
{
	size_t	length;

	length = 0;
	while ((*raw)[length] && \
(
(*raw)[length] != '\'' && \
(*raw)[length] != '\"' && \
(*raw)[length] != '$'
))
		length++;
	*out = str_lrealloc(*out, *raw, length, 0);
	str_lclean(raw, length);
}

char	*expand(char *raw, t_shell *sh)
{
	char	*out;

	out = 0;
	while (raw)
	{
		if (*raw == '$')
			var_append(&raw, &out, sh);
		else if (str_mc(&raw, "\""))
			dq_append(&raw, &out, sh);
		else if (str_mc(&raw, "\'"))
			sq_append(&raw, &out, sh);
		else
			raw_append(&raw, &out);
	}
	return (out);
}
