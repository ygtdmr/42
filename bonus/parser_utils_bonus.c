/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:51 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/11 05:47:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	argv_push(char ***dest, char *src)
{
	char	**argv;
	int		i;

	if (!src)
		return ;
	i = 0;
	while (*dest && (*dest)[i])
		i++;
	argv = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (*dest && (*dest)[i])
	{
		argv[i] = (*dest)[i];
		i++;
	}
	argv[i] = ft_strdup(src);
	if (*dest)
		free(*dest);
	*dest = argv;
}

t_cmd	*new_cmd(t_cmd **head, t_token *token)
{
	t_cmd	*last_head;
	t_cmd	*new;

	if (!head)
		return (0);
	last_head = 0;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(t_cmd));
	new->op = -1;
	new->token = token;
	if (*head)
	{
		last_head = *head;
		while (last_head->next)
			last_head = last_head->next;
		new->prev = last_head;
		last_head->next = new;
	}
	else
		*head = new;
	return (new);
}

void	clear_cmd(t_cmd **head, int op)
{
	t_cmd	*tmp_cmd;
	t_redir	*redir;

	if (!head || !*head)
		return ;
	clear_sl((*head)->argv);
	while ((*head)->redir_head)
	{
		redir = (*head)->redir_head->next;
		free((*head)->redir_head);
		(*head)->redir_head = redir;
	}
	if ((*head)->cmd_subsh)
		clear_cmd(&(*head)->cmd_subsh, 2);
	if ((*head)->tok_subsh)
		clear_tok(&(*head)->tok_subsh);
	tmp_cmd = (*head)->next;
	free(*head);
	*head = tmp_cmd;
	if (*head)
		(*head)->prev = 0;
	if (*head && (*head)->op != op)
		clear_cmd(head, op);
	else if (*head)
		(*head)->op = -1;
}

t_cmd	*cmd_by_pid(t_cmd *head, pid_t pid)
{
	while (head && (head->pid != pid))
		head = head->next;
	return (head);
}

t_cmd	*last_cmd(t_cmd *head)
{
	while (head && head->next && head->next->op == -1)
		head = head->next;
	return (head);
}
