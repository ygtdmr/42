/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:51 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/29 07:02:06 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	argv_push(char ***dest, char *src)
{
	char	**argv;
	int		i;

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
	argv[i] = src;
	if (*dest)
		free(*dest);
	*dest = argv;
}

t_cmd	*new_cmd(t_cmd **head)
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
	if (*head)
	{
		last_head = *head;
		while (last_head->next)
			last_head = last_head->next;
		last_head->next = new;
	}
	else
		*head = new;
	return (new);
}

void	clear_cmd(t_cmd **head)
{
	int		i;
	t_cmd	*cmd;
	t_redir	*redir;

	i = 0;
	if (!head)
		return ;
	cmd = *head;
	if (!cmd)
	return ;
	free(cmd->argv);
	while (cmd->redir_head)
	{
		redir = cmd->redir_head->next;
		free(cmd->redir_head);
		cmd->redir_head = redir;
	}
	if (cmd->next)
		clear_cmd(&cmd->next);
	free(cmd);
	*head = 0;
}
