/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:11 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/20 14:50:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "minishell.h"
#include "executer.h"

static char	*env_key(char *src)
{
	char	*key;
	size_t	length;

	length = ft_strlen(src) - ft_strlen(ft_strchr(src, '='));
	key = ft_calloc(length + 1, sizeof(char));
	ft_strlcpy(key, src, length + 1);
	return (key);
}

static size_t	env_len(char **env)
{
	size_t	len;

	len = 0;
	while (env[len])
		len++;
	return (len);
}

int	env_var_exists(char **env, char *src)
{
	char	*key;
	char	*tmp_key;

	key = env_key(src);
	while (*env)
	{
		tmp_key = env_key(*env);
		if (str_match(key, tmp_key))
		{
			free(key);
			free(tmp_key);
			return (1);
		}
		free(tmp_key);
		env++;
	}
	free(key);
	return (0);
}

void	clear_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

char	**env_append(char **env, char *src)
{
	size_t	i;
	size_t	len;
	char	**env_dup;

	i = 0;
	len = env_len(env);
	env_dup = ft_calloc(len + (src != 0) + 1, sizeof(char *));
	while (env[i])
	{
		env_dup[i] = ft_strdup(env[i]);
		i++;
	}
	if (src)
		env_dup[i] = src;
	return (env_dup);
}

char	**env_set(char **env, char *src, int unset)
{
	size_t	i;
	char	*key;
	char	*tmp_key;
	char	**env_dup;

	i = 0;
	key = env_key(src);
	env_dup = ft_calloc((env_len(env) - unset) + 1, sizeof(char *));
	while (env[i])
	{
		tmp_key = env_key(env[i]);
		if (str_match(tmp_key, key))
		{
			if (unset)
				env_dup[i] = ft_strdup(env[i + 1]);
			else
				env_dup[i] = src;
		}
		else
			env_dup[i] = ft_strdup(env[i]);
		i++;
		free(tmp_key);
	}
	free(key);
	return (env_dup);
}
