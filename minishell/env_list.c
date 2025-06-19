/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:11 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/19 18:36:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_key(char *env)
{
	char	*key;
	size_t	length;

	length = ft_strlen(env) - ft_strlen(ft_strchr(env, '='));
	key = ft_calloc(length + 1, sizeof(char));
	ft_strlcpy(key, env, length + 1);
	return (key);
}

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

void	clear_env_list(t_env **head)
{
	t_env	*env;

	if (!head)
		return ;
	env = *head;
	if (!env)
		return ;
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	if (env->next)
		clear_env_list(&env->next);
	free(env);
	*head = 0;
}

t_env	*env_list(char **envp)
{
	t_env	*head;

	head = 0;
	while (envp && *envp)
		add_env(&head, *envp++);
	return (head);
}

char	**envl_to_envp(t_env *env_list)
{
	t_env	*list;
	size_t	length;
	char	**envp;
	char	**f_envp;

	list = env_list;
	length = 0;
	while (list)
	{
		length++;
		list = list->next;
	}
	envp = ft_calloc(length + 1, sizeof(char *));
	f_envp = envp;
	list = env_list;
	while (list)
	{
		*envp = str
		list = list->next;
	}
	return (f_envp);
}
