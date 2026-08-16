/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:11 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/09 10:42:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_key_match(char *src, char *key)
{
	int		result;
	char	*tmp_key;

	if (!src)
		return (0);
	tmp_key = env_key(src);
	result = str_match(tmp_key, key);
	free(tmp_key);
	return (result);
}

char	**env_dup(char **env, int clear)
{
	char	**dup;
	size_t	length;
	size_t	i;

	i = 0;
	length = 0;
	while (env[length])
		length++;
	dup = ft_calloc(length + 1, sizeof(char *));
	while (i < length)
	{
		dup[i] = ft_strdup(env[i]);
		i++;
	}
	if (clear)
		clear_sl(env);
	return (dup);
}

char	*env_get(char **env, char *key)
{
	if (!key)
		return (0);
	while (*env)
	{
		if (env_key_match(*env, key) && ft_strchr(*env, '='))
			return (ft_strchr(*env, '=') + 1);
		env++;
	}
	return (0);
}

static void	env_set(char ***env, char *key, char *val)
{
	size_t	i;
	char	**dup;

	i = 0;
	dup = env_dup(*env, 1);
	while (dup[i])
	{
		if (env_key_match(dup[i], key))
		{
			free(dup[i]);
			dup[i] = env_str(key, val);
			if (!val)
			{
				free(dup[i]);
				while (dup[++i])
					dup[i - 1] = dup[i];
				dup[i - 1] = 0;
				free(dup[i]);
			}
			break ;
		}
		i++;
	}
	*env = dup;
}

void	env_append(char ***env, char *key, char *val)
{
	char	**dup;
	size_t	i;

	i = 0;
	if (env_key_exists(*env, key))
		env_set(env, key, val);
	else
	{
		while ((*env)[i])
			i++;
		dup = ft_calloc(i + 2, sizeof(char *));
		i = 0;
		while ((*env)[i])
		{
			dup[i] = ft_strdup((*env)[i]);
			i++;
		}
		clear_sl(*env);
		dup[i] = env_str(key, val);
		*env = dup;
	}
}
