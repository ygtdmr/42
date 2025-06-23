/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:23:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 19:31:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"
#include "str_utils.h"
#include "expand.h"

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

	index = 0;
	while (src[index] && src[index] != '=')
	{
		if (!is_varchar(src[index], index))
			return (0);
		src++;
	}
	return (1);
}
