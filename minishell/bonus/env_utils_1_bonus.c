/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:11 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 14:05:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "str_utils_bonus.h"
#include "env_utils_bonus.h"

char	*env_key(char *src)
{
	char	*key;
	size_t	length;

	if (!src)
		return (0);
	if (ft_strchr(src, '='))
		length = ft_strlen(src) - ft_strlen(ft_strchr(src, '='));
	else
		length = ft_strlen(src);
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

char	*env_get(char **env, char *key)
{
	char	*tmp_key;

	if (!key)
		return (0);
	while (*env)
	{
		tmp_key = env_key(*env);
		if (str_match(key, tmp_key))
		{
			free(tmp_key);
			return (ft_strchr(*env, '=') + 1);
		}
		free(tmp_key);
		env++;
	}
	return (0);
}

char	**env_append(char **env, char *src)
{
	size_t	i;
	char	**env_dup;
	char	**env_tmp;
	int		src_has_val;

	if (src && env_key_exists(env, src))
	{
		env_tmp = env_set(env, src, 0);
		clear_env(env);
		return (env_tmp);
	}
	i = 0;
	src_has_val = (src && ft_strchr(src, '='));
	env_dup = ft_calloc(env_len(env) + src_has_val + 1, sizeof(char *));
	while (env[i])
	{
		env_dup[i] = ft_strdup(env[i]);
		i++;
	}
	if (src_has_val)
		env_dup[i] = ft_strdup(src);
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
	while (*env)
	{
		tmp_key = env_key(*env);
		if (str_match(tmp_key, key))
		{
			if (!unset)
				env_dup[i++] = ft_strdup(src);
		}
		else
			env_dup[i++] = ft_strdup(*env);
		env++;
		free(tmp_key);
	}
	free(key);
	return (env_dup);
}
