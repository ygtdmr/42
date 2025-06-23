/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:23:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 16:22:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_utils.h"
#include "str_utils.h"

void	clear_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

char	*env_get(char **env, char *key)
{
	char	*tmp_key;

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
	free(key);
	return (0);
}
