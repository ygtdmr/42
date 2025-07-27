/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:23:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 13:53:32 by yidemir          ###   ########.fr       */
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

int	env_key_validate(char *src, char *err_type)
{
	size_t	index;
	int		status;

	status = 1;
	if (!src || *src == '=')
		status = 0;
	index = 0;
	while (status && (src[index] && src[index] != '='))
	{
		if (!is_varchar(src[index], index))
			status = 0;
		index++;
	}
	if (!status)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(err_type, 2);
		ft_putstr_fd(src, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		return (0);
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
