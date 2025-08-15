/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:23:36 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 13:45:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*env_str(char *key, char *val)
{
	char	*tmp;

	if (!key)
		return (0);
	tmp = 0;
	if (!val)
		return (ft_strdup(key));
	else
	{
		tmp = ft_strdup(key);
		if (!tmp)
			return (0);
		tmp = str_realloc(tmp, "=", 0);
		if (*val)
			tmp = str_realloc(tmp, val, 0);
		free(val);
	}
	return (tmp);
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

int	env_key_validate(char *src, char *err_type, int unset)
{
	size_t	index;
	int		status;

	status = 0;
	if (src && *src == '-')
		status = 2;
	else if (!unset)
		status = (!src || *src == '=');
	index = 0;
	while (!unset && !status && (src[index] && src[index] != '='))
	{
		status = !(is_varchar(src, index) || \
(src[index] == '+' && src[index + 1] == '='));
		index++;
	}
	if (!status)
		return (0);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(err_type, 2);
	ft_putstr_fd(src, 2);
	if (status == 2)
		ft_putendl_fd(": options are not supported", 2);
	else
		ft_putendl_fd(": not a valid identifier", 2);
	return (status);
}

char	*env_key(char *src)
{
	char	*key;
	size_t	length;

	if (!src)
		return (0);
	if (ft_strchr(src, '='))
		length = ft_strlen(src) - ft_strlen(ft_strchr(src, '=')) \
- (*(ft_strchr(src, '=') - 1) == '+');
	else
		length = ft_strlen(src);
	key = ft_calloc(length + 1, sizeof(char));
	ft_strlcpy(key, src, length + 1);
	return (key);
}
