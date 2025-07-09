/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:23:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 14:05:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "env_utils_bonus.h"
#include "str_utils_bonus.h"
#include "expand_bonus.h"

void	clear_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

int	env_key_exists(char **env, char *src)
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
