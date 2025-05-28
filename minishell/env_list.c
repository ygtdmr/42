/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:18:11 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/28 13:00:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_env(t_env **head, t_env *new)
{
	t_env	*env;

	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	env = *head;
	while (env->next)
		env = env->next;
	env->next = new;
}

void	new_enw(t_env **head, char *value)
{
	t_env	*new;
	char	**dict;

	if (!value)
		return ;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	dict = ft_split(value, '=');
	new->key = dict[0];
	new->value = dict[1];
	new->next = 0;
	free(dict);
	add_env(head, new);
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
		new_enw(&head, *envp++);
	return (head);
}
