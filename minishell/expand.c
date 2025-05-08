/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 00:42:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/09 00:05:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

static void	var_append(char **raw, char **out, t_shell *sh)
{
	char	*var;
	char	*var_name;
	size_t	length;

	length = 0;
	if (**raw == '?' && *raw++)
		var = ft_itoa(sh->last_status);
	else
	{
		while (is_varchar((*raw)[length], length))
			length++;
		var_name = ft_calloc(length, sizeof(char));
		ft_strlcpy(var_name, *raw, length + 1);
		var = getenv(var_name);
		free(var_name);
		*raw += length;
	}
	if (var)
		*out = str_lrealloc(*out, var, ft_strlen(var));
}

static void	dq_append(char **raw, char **out, t_shell *sh)
{
	size_t	length;

	length = 1;
	while ((*raw)[length] != '\"')
	{
		if ((*raw)[length] == '$')
		{
			*out = str_lrealloc(*out, *raw, length);
			*raw += (length + 1);
			length = 0;
			var_append(raw, out, sh);
		}
		length += (1 + (*raw)[length] == '\\'); // fix this issue
	}
	*out = str_lrealloc(*out, *raw, ++length);
	*raw += length;
}

static void	sq_append(char **raw, char **out)
{
	size_t	length;

	length = 1;
	while ((*raw)[length] != '\'')
		length++;
	*out = str_lrealloc(*out, *raw, ++length);
	*raw += length;
}

static void	raw_append(char **raw, char **out)
{
	size_t	length;

	length = 0;
	while (
		(*raw)[length] && \
		(
			(*raw)[length] != '\'' || \
			(*raw)[length] != '\"' || \
			(*raw)[length] != '$'
		)
	)
		length++;
	*out = str_lrealloc(*out, *raw, length);
	*raw += length;
}

char	*expand(char *raw, t_shell *sh)
{
	char	*fraw;
	char	*out;

	fraw = raw;
	out = 0;
	while (*raw)
	{
		if (*raw == '$' && raw++)
			var_append(&raw, &out, sh);
		else if (*raw == '\"')
			dq_append(&raw, &out, sh);
		else if (*raw == '\'')
			sq_append(&raw, &out);
		else
			raw_append(&raw, &out);
	}
	free(fraw);
	return (out);
}
