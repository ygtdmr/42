/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:11 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/20 05:14:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executer.h"

static void	add_env(t_env **head, char *value)
{
	t_env	*last_head;
	t_env	*new;

	if (!(head && value))
		return ;
	last_head = 0;
	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = env_key(value);
	new->value = ft_strdup(ft_strchr(value, '=') + 1);
	new->next = 0;
	if (*head)
	{
		last_head = *head;
		while (last_head->next)
			last_head = last_head->next;
		last_head->next = new;
	}
	else
		*head = new;
}

static char	*env_key(char *src)
{
	char	*key;
	size_t	length;

	length = ft_strlen(src) - ft_strlen(ft_strchr(src, '='));
	key = ft_calloc(length + 1, sizeof(char));
	ft_strlcpy(key, src, length + 1);
	return (key);
}

static size_t env_len(char **envp)
{
	size_t	len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}

char	*env_set(char **envp, char *src, int unset)
{
	size_t	i;
	char	*key;
	char	*tmp_key;
	char	**env_dup;

	i = 0;
	key = env_key(src);
	env_dup = ft_calloc((env_len(envp) - unset) + 1, sizeof(char *));
	while (envp[i])
	{
		tmp_key = env_key(envp[i]);
		if (str_match(tmp_key, key) && unset)
		{
			env_dup[i] = ft_strdup(envp[i + 1]);
			i += 2;
		}
		else
		{
			env_dup[i] = ft_strdup(envp[i]);
			i++;
		}
		free(tmp_key);
	}
	free(key);
	return (env_dup);
}
