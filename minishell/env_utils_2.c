/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:23:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 09:31:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_str(char *key, char *val)
{
	char	*tmp;

	if (!key)
		return (NULL);
	tmp = NULL;
	if (val == NULL)
		return (ft_strdup(key));
	else
	{
		tmp = ft_strdup(key);
		if (!tmp)
			return (NULL);
		tmp = str_lrealloc(tmp, "=", 1, 0);
		if (val && *val)
			tmp = str_lrealloc(tmp, val, ft_strlen(val), 1);
	}
	return (tmp);
}

void	clear_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

int	env_key_exists(char **env, char *key)
{
	char	*tmp_key;

	while (*env)
	{
		tmp_key = env_key(*env);
		if (str_match(key, tmp_key))
		{
			free(tmp_key);
			return (1);
		}
		free(tmp_key);
		env++;
	}
	return (0);
}

int	env_key_valid(char *src)
{
	size_t	index;

	if (!src || *src == '=')
		return (0);
	index = 0;
	while (src[index] && src[index] != '=')
	{
		if (!is_varchar(src[index], index))
			return (0);
		index++;
	}
	return (1);
}

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
