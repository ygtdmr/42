/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   willcard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 06:54:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 13:53:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	index_is_wc(t_token *token, size_t i)
{
	size_t	tmp_i;

	tmp_i = 0;
	while (tmp_i < token->len_wc)
	{
		if (i == token->i_wc[tmp_i])
			return (1);
		tmp_i++;
	}
	return (0);
}

static int	willcard_match(char *d_name, t_token *token, size_t i)
{
	if (token->value[i] == '\0')
		return (*d_name == '\0');
	if (index_is_wc(token, i))
	{
		if (token->value[i + 1] == '\0')
			return (1);
		while (*d_name != '\0')
		{
			if (willcard_match(d_name, token, i + 1))
				return (1);
			d_name++;
		}
		return (willcard_match(d_name, token, i + 1));
	}
	if (*d_name != '\0' && token->value[i] == *d_name)
		return (willcard_match(d_name + 1, token, i + 1));
	return (0);
}

void	argv_push_with_willcard(char ***argv, t_token *token)
{
	int				expand;
	char			*cwd;
	DIR				*dir;
	struct dirent	*drn;

	if (!token->i_wc)
		return (argv_push(argv, token->value));
	expand = 0;
	cwd = getcwd(0, 0);
	dir = opendir(cwd);
	free(cwd);
	while (1)
	{
		drn = readdir(dir);
		if (!drn)
			break ;
		if (*(drn->d_name) == '.' && *(token->value) != '.')
			continue ;
		if ((willcard_match(drn->d_name, token, 0)) && ++expand)
			argv_push(argv, drn->d_name);
	}
	closedir(dir);
	if (!expand)
		argv_push(argv, token->value);
}

void	var_tok_willcard(t_shell *sh, t_token *token, char *value)
{
	int		i;
	char	quote;

	quote = 0;
	i = 0;
	while (value && value[i])
	{
		if (!quote && (value[i] == '\'' || value[i] == '\"'))
			quote = value[i];
		else if (quote == value[i])
			quote = 0;
		if (value[i] != '\\')
		{
			if (!quote && value[i] == '*')
			{
				if (token)
					i_wc_push(&token->i_wc, &token->len_wc, i);
				else
					i_wc_push(&sh->i_wc, &sh->len_wc, i);
			}
		}
		else
			i++;
		i++;
	}
}

void	i_wc_push(size_t **i_wc, size_t *len, size_t new)
{
	size_t	*i_wc_dup;
	size_t	index;

	index = 0;
	i_wc_dup = malloc(sizeof(size_t) * ((*len) + 1));
	if (!i_wc_dup)
		return ;
	while (index < *len)
	{
		i_wc_dup[index] = (*i_wc)[index];
		index++;
	}
	if (*i_wc)
		free(*i_wc);
	i_wc_dup[index] = new;
	*i_wc = i_wc_dup;
	(*len) += 1;
}
